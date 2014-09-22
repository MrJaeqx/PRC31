#include <string>
#include "gtest/gtest.h"
#include "Meetserie.h"

#include <stdio.h>
using namespace std;

TEST(TestNaam, startSerieNaam)
{
    Meetserie ms("test");
    EXPECT_EQ(ms.getNaam(), "test");
}

TEST(TestNaam, changeSerieNaam)
{
    string name = "Henk";
    string nameChanged = "Piet";
    Meetserie ms(name);
    ASSERT_EQ(ms.getNaam(), name);
    ms.setNaam(nameChanged);
    EXPECT_EQ(ms.getNaam(), nameChanged);
}

TEST(TestVol, serieNietVol)
{
    string name = "test";
    Meetserie ms(name);
    EXPECT_FALSE(ms.isVol());
}

TEST(TestVol, serieWelVol)
{
    string name = "test";
    Meetserie ms(name);
    ASSERT_FALSE(ms.isVol());
    for(int i = 0; i < 10; i++)
    {
        ms.voegToe(1);
    }
    EXPECT_TRUE(ms.isVol());
}

TEST(TestVindMeetwaarde, serieVindGeenMeetwaarde)
{
    string name = "test";
    Meetserie ms(name);
    ms.voegToe(1);
    EXPECT_FALSE(ms.meetwaardeKomtVoor(0));
}

TEST(TestVindMeetwaarde, serieVindWelMeetwaarde)
{
    string name = "test";
    Meetserie ms(name);
    ms.voegToe(1);
    EXPECT_TRUE(ms.meetwaardeKomtVoor(1));
}

TEST(TestGetMeetwaarde, serieGetMeetwaarde)
{
    string name = "test";
    Meetserie ms(name);
    int value = 10;
    ms.voegToe(value);
    EXPECT_EQ(ms.getMeetwaarde(0), value);
}

TEST(TestTelAantalWaardes, serieTelWaardes)
{
    string name = "test";
    Meetserie ms(name);
    ms.voegToe(1);
    ms.voegToe(5);
    int aantal = 0;
    ms.bepAantalMeetwaarden(aantal);
    EXPECT_EQ(aantal, 2);
}

class MeetSerieTest : public ::testing::Test {
protected:
    Meetserie ms;
};