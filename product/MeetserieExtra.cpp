#include "MeetserieExtra.h"
#include <iostream>
#include <string>

using namespace std;

//---------------------------------------------------------------------------

MeetserieExtra::MeetserieExtra(string nm)
    : Meetserie(nm)
{
	aantalVerschillendeWaarden = 0;
}

int MeetserieExtra::getAantalKeer(int meetw)
{
	int totaal = 0;
	int i = 0;
	for (; totaal < MaxAantalMeetwaarden; i++)
	{
		if(meetw == getMeetwaarde(i))
		{
			totaal++;
		}
	}
	return totaal;
}

void MeetserieExtra::voegToeMeetserie( Meetserie &meets )
{
	int aantalMeetwaardenMeets = 0;
	meets.bepAantalMeetwaarden(aantalMeetwaardenMeets);
	int aantalMeetwaarden = 0;
	bepAantalMeetwaarden(aantalMeetwaarden);
	if(aantalMeetwaardenMeets < (MaxAantalMeetwaarden - aantalMeetwaarden))
	{
		cout << "Meetserie is vol";
	}
	else
	{
		int i = 0;
		for(; i < aantalMeetwaardenMeets; i++)
		{
			voegToe(meets.getMeetwaarde(i));
		}
	}
}

void MeetserieExtra::voegToe(int meetw)
{
	Meetserie::voegToe(meetw);
}

int MeetserieExtra::getAantalVerschillendeWaarden()
{
	int aantalMeetwaarden = 0;
	int verschillendeMeetwaarden = 0;
	bepAantalMeetwaarden(aantalMeetwaarden);
	int i = 0;
	int j = 0;
	for(; i < aantalMeetwaarden; i++)
	{
		for(; j < aantalMeetwaarden; j++)
		{
			if(getMeetwaarde(i) == getMeetwaarde(j) && i != j)
			{
				verschillendeMeetwaarden++;
			}
		}
	}

	return verschillendeMeetwaarden;
}