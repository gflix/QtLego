#include <models/LeMessageHubDetachedIo.hpp>
#include <models/LeMessageHubAttachedIo.hpp>
#include <protocols/GenericLeMessage.hpp>
#include <unittest/protocols/GenericLeMessageTest.hpp>

using namespace Lego;

void GenericLeMessageTest::throwsWhenExtractingFrameMetricsFromEmptyQByteArray()
{
    // setup
    auto data = QByteArray();

    // exercise and verify
    QVERIFY_EXCEPTION_THROWN(extractFrameMetrics(data), std::invalid_argument);
}

void GenericLeMessageTest::throwsWhenExtractingFrameMetricsFromOneByteQByteArrayIndicatingSecondSizeByte()
{
    // setup
    auto data = QByteArray::fromHex("80");

    // exercise and verify
    QVERIFY_EXCEPTION_THROWN(extractFrameMetrics(data), std::invalid_argument);
}

void GenericLeMessageTest::extractsFrameMetricsFromQByteArrayWithOneByteSize()
{
    // setup
    auto data = QByteArray::fromHex("0c");

    QPair<int, int> expected { 12, 1 };

    // exercise and verify
    QCOMPARE(extractFrameMetrics(data), expected);
}

void GenericLeMessageTest::extractsFrameMetricsFromQByteArrayWithTwoByteSize()
{
    // setup
    auto data = QByteArray::fromHex("8201");

    QPair<int, int> expected { 130, 2 };

    // exercise and verify
    QCOMPARE(extractFrameMetrics(data), expected);
}

void GenericLeMessageTest::throwsWhenCheckingFrameMetricsWithTooShortMessage()
{
    // setup
    auto data = QByteArray::fromHex("02");

    // exercise and verify
    QVERIFY_EXCEPTION_THROWN(decodeLeMessage(data), std::invalid_argument);
}

void GenericLeMessageTest::throwsWhenCheckingFrameMetricsWithTooLongMessage()
{
    // setup
    auto data = QByteArray::fromHex("020000");

    // exercise and verify
    QVERIFY_EXCEPTION_THROWN(decodeLeMessage(data), std::invalid_argument);
}

void GenericLeMessageTest::throwsWhenCheckingFrameMetricsWithInvalidHeaderLength()
{
    // setup
    auto data = QByteArray::fromHex("0200");

    // exercise and verify
    QVERIFY_EXCEPTION_THROWN(decodeLeMessage(data), std::invalid_argument);
}

void GenericLeMessageTest::throwsWhenDecodingLeMessageWithInvalidHubId()
{
    // setup
    auto data = QByteArray::fromHex("030100");

    // exercise and verify
    QVERIFY_EXCEPTION_THROWN(decodeLeMessage(data), std::domain_error);
}

void GenericLeMessageTest::decodesHubAttachedIoMessage()
{
    // setup
    auto data = QByteArray::fromHex("0500040001");

    // exercise
    auto actual = decodeLeMessage(data);

    QVERIFY(cast<LeMessageHubAttachedIo>(actual));
}

void GenericLeMessageTest::decodesHubDetachedIoMessage()
{
    // setup
    auto data = QByteArray::fromHex("0500040000");

    // exercise
    auto actual = decodeLeMessage(data);

    QVERIFY(cast<LeMessageHubDetachedIo>(actual));
}
