#include <gtest/gtest.h>
#include <utils/Converter.hpp>

using namespace Lego;

TEST(ConverterTest, throwsWhenConvertingByteArrayToUnsignedCharWithWrongLength)
{
    // setup
    auto data = QByteArray::fromHex("0100");

    // exercise and verify
    EXPECT_THROW(Converter::byteArrayToUnsignedChar(data), std::invalid_argument);
}

TEST(ConverterTest, convertsByteArrayToUnsignedChar)
{
    // setup
    auto data = QByteArray::fromHex("81");

    unsigned char expected = 129;

    // exercise and verify
    EXPECT_EQ(expected, Converter::byteArrayToUnsignedChar(data));
}

TEST(ConverterTest, throwsWhenConvertingByteArrayToCharWithWrongLength)
{
    // setup
    auto data = QByteArray::fromHex("0100");

    // exercise and verify
    EXPECT_THROW(Converter::byteArrayToChar(data), std::invalid_argument);
}

TEST(ConverterTest, convertsByteArrayToChar)
{
    // setup
    auto data = QByteArray::fromHex("83");

    char expected = -125;

    // exercise and verify
    EXPECT_EQ(expected, Converter::byteArrayToChar(data));
}

TEST(ConverterTest, throwsWhenConvertingByteArrayToUnsignedShortLeWithWrongLength)
{
    // setup
    auto data = QByteArray::fromHex("01");

    // exercise and verify
    EXPECT_THROW(Converter::byteArrayToUnsignedShortLe(data), std::invalid_argument);
}

TEST(ConverterTest, convertsByteArrayToUnsignedShortLeI)
{
    // setup
    auto data = QByteArray::fromHex("aa60");

    unsigned short expected = 24746;

    // exercise and verify
    EXPECT_EQ(expected, Converter::byteArrayToUnsignedShortLe(data));
}

TEST(ConverterTest, convertsByteArrayToUnsignedShortLeII)
{
    // setup
    auto data = QByteArray::fromHex("0140");

    unsigned short expected = 16385;

    // exercise and verify
    EXPECT_EQ(expected, Converter::byteArrayToUnsignedShortLe(data));
}
