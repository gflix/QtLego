#include <gtest/gtest.h>
#include <models/LeMessageHubDetachedIo.hpp>
#include <models/LeMessageHubAttachedIo.hpp>
#include <protocols/GenericLeMessage.hpp>

using namespace Lego;

TEST(GenericLeMessageTest, throwsWhenExtractingFrameMetricsFromEmptyQByteArray)
{
    // setup
    auto data = QByteArray();

    // exercise and verify
    EXPECT_THROW(extractFrameMetrics(data), std::invalid_argument);
}

TEST(GenericLeMessageTest, throwsWhenExtractingFrameMetricsFromOneByteQByteArrayIndicatingSecondSizeByte)
{
    // setup
    auto data = QByteArray::fromHex("80");

    // exercise and verify
    EXPECT_THROW(extractFrameMetrics(data), std::invalid_argument);
}

TEST(GenericLeMessageTest, extractsFrameMetricsFromQByteArrayWithOneByteSize)
{
    // setup
    auto data = QByteArray::fromHex("0c");

    QPair<int, int> expected { 12, 1 };

    // exercise and verify
    EXPECT_EQ(expected, extractFrameMetrics(data));
}

TEST(GenericLeMessageTest, extractsFrameMetricsFromQByteArrayWithTwoByteSize)
{
    // setup
    auto data = QByteArray::fromHex("8201");

    QPair<int, int> expected { 130, 2 };

    // exercise and verify
    EXPECT_EQ(expected, extractFrameMetrics(data));
}

TEST(GenericLeMessageTest, throwsWhenCheckingFrameMetricsWithTooShortMessage)
{
    // setup
    auto data = QByteArray::fromHex("02");

    // exercise and verify
    EXPECT_THROW(decodeLeMessage(data), std::invalid_argument);
}

TEST(GenericLeMessageTest, throwsWhenCheckingFrameMetricsWithTooLongMessage)
{
    // setup
    auto data = QByteArray::fromHex("020000");

    // exercise and verify
    EXPECT_THROW(decodeLeMessage(data), std::invalid_argument);
}

TEST(GenericLeMessageTest, throwsWhenCheckingFrameMetricsWithInvalidHeaderLength)
{
    // setup
    auto data = QByteArray::fromHex("0200");

    // exercise and verify
    EXPECT_THROW(decodeLeMessage(data), std::invalid_argument);
}

TEST(GenericLeMessageTest, throwsWhenDecodingLeMessageWithInvalidHubId)
{
    // setup
    auto data = QByteArray::fromHex("030100");

    // exercise and verify
    EXPECT_THROW(decodeLeMessage(data), std::domain_error);
}

TEST(GenericLeMessageTest, decodesHubAttachedIoMessage)
{
    // setup
    auto data = QByteArray::fromHex("07 00 04 01 01 2000");
    auto expected = QString("LeMessageHubAttachedIo[port=1,ioType=32]");

    // exercise
    QString actual;
    QTextStream stream(&actual);
    stream << decodeLeMessage(data);

    EXPECT_EQ(expected.toStdString(), actual.toStdString());
}

TEST(GenericLeMessageTest, decodesHubDetachedIoMessage)
{
    // setup
    auto data = QByteArray::fromHex("0500040000");
    auto expected = QString("LeMessageHubDetachedIo[port=0]");

    // exercise
    QString actual;
    QTextStream stream(&actual);
    stream << decodeLeMessage(data);

    EXPECT_EQ(expected.toStdString(), actual.toStdString());
}
