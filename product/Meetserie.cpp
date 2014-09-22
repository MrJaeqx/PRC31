#include "Meetserie.h"
#include <iostream>
#include <string>
using namespace std;



//---------------------------------------------------------------------------

Meetserie::Meetserie(string nm)
    : naam(nm)
    , count(0)
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
    return count >= MaxAantalMeetwaarden;
}

// done
void Meetserie::voegToe(int meetw)
{
	if (!isVol())
	{
		meetwaarden[count] = meetw;
		count++;
	}
	else
	{
		cout << "\nSerie is vol.";
	}
}

//done
bool Meetserie::meetwaardeKomtVoor(int meetw)
{
	int i = 0;
	for (; i < count; i++)
	{
		if (meetwaarden[i] == meetw)
		{
			return true;
		}
	}
	return false;
}

//done
int Meetserie::getMeetwaarde(int i)
{
    return meetwaarden[i];
}


//done
void Meetserie::bepAantalMeetwaarden(int &aantal)
{
    aantal = count;
}