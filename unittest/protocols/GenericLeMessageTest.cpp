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
