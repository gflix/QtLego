#include <gtest/gtest.h>
#include <protocols/IoType.hpp>

using namespace Lego;

TEST(IoTypeTest, convertsIoTypeToIdentifier)
{
    // setup
    auto expected = QString("TECHNIC_L_MOTOR");

    // exercise
    auto actual = ioTypeToIdentifier(IoType::TECHNIC_L_MOTOR);

    // verify
    EXPECT_EQ(expected.toStdString(), actual.toStdString());
}

TEST(IoTypeTest, convertsInvalidIoTypeToUnknownIdentifier)
{
    // setup
    auto expected = QString("UNKNOWN");

    // exercise
    auto actual = ioTypeToIdentifier(static_cast<IoType>(-2));

    // verify
    EXPECT_EQ(expected.toStdString(), actual.toStdString());
}

TEST(IoTypeTest, convertsIoTypeFromIdentifier)
{
    // setup
    auto expected = IoType::VOLTAGE;

    // exercise
    auto actual = ioTypeFromIdentifier("VOLTAGE");

    // verify
    EXPECT_EQ(expected, actual);
}

TEST(IoTypeTest, convertsIoTypeFromUnknownIdentifier)
{
    // setup
    auto expected = IoType::UNKNOWN;

    // exercise
    auto actual = ioTypeFromIdentifier("foobar");

    // verify
    EXPECT_EQ(expected, actual);
}
