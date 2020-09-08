#include <gtest/gtest.h>
#include <models/GenericLeMessage.hpp>

using namespace Lego;

TEST(GenericLeMessageTest, dumpsLeMessageWithNullPointer)
{
    // setup
    auto leMessage = LeMessage();
    auto expected = QString("GenericLeMessage[null]");

    // exercise
    QString actual;
    QTextStream stream(&actual);
    stream << leMessage;

    EXPECT_EQ(expected.toStdString(), actual.toStdString());
}

TEST(GenericLeMessageTest, dumpsLeMessageWithGenericLeMessage)
{
    // setup
    auto leMessage = LeMessage(new GenericLeMessage());
    auto expected = QString("GenericLeMessage[]");

    // exercise
    QString actual;
    QTextStream stream(&actual);
    stream << leMessage;

    EXPECT_EQ(expected.toStdString(), actual.toStdString());
}
