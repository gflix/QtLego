#ifndef UNITTEST_PROTOCOLS_GENERICLEMESSAGETEST_HPP_
#define UNITTEST_PROTOCOLS_GENERICLEMESSAGETEST_HPP_

#include <QtTest/QtTest>

class GenericLeMessageTest: public QObject
{
    Q_OBJECT

private slots:
    void throwsWhenExtractingFrameMetricsFromEmptyQByteArray();
    void throwsWhenExtractingFrameMetricsFromOneByteQByteArrayIndicatingSecondSizeByte();
    void extractsFrameMetricsFromQByteArrayWithOneByteSize();
    void extractsFrameMetricsFromQByteArrayWithTwoByteSize();

    void throwsWhenCheckingFrameMetricsWithTooShortMessage();
    void throwsWhenCheckingFrameMetricsWithTooLongMessage();
    void throwsWhenCheckingFrameMetricsWithInvalidHeaderLength();

    void throwsWhenDecodingLeMessageWithInvalidHubId();

    void decodesHubAttachedIoMessage();
    void decodesHubDetachedIoMessage();
};

#endif /* UNITTEST_PROTOCOLS_GENERICLEMESSAGETEST_HPP_ */
