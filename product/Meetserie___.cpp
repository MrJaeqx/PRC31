#include "Meetserie.h"
#include <iostream>
#include <string>
using namespace std;



//---------------------------------------------------------------------------

Meetserie::Meetserie(string nm)
    : naam(nm)
    , balans(0)
    , meetwaarden[MaxAantalMeetwaarden]
{
}

string Meetserie::getNaam()
{
	return naam;
}

void Meetserie::setNaam(string nm)
{
	naam = nm;
}

bool Meetserie::isVol()
{
    if(count(meetwaarden) > MaxAantalMeetwaarden)
    {
    	return true;
    }
    else
    {
    	return false;
    }
}

// done
void Meetserie::voegToe(int meetw)
{
	int aantMeetWaarden = 0;
    bepAantalMeetwaarden(aantMeetWaarden);

    meetwaarden[aantMeetWaarden + 1]  = meetw;
}

//done
bool Meetserie::meetwaardeKomtVoor(int meetw)
{
    bool komtVoor = false;
    int i = 0;
    for(;i < MaxAantalMeetwaarden; i++)
    {
        if(getMeetWaarde(i) == meetw)
        {
            komtVoor = true;
        }
    }
}

//done
int Meetserie::getMeetWaarde(int i)
{
    return meetwaarden[i];
}


//done
void bepAantalMeetwaarden(int &aantal)
{
    int i = 0;
    for(;i < MaxAantalMeetwaarden; i++)
    {
        if(getMeetWaarde(i) != NULL)
        {
            *aantal++;
        }
    }
}