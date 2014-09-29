//============================================================================
// Name        : menu.cpp
// Author      : Peter Lambooij
// Version     :
// Copyright   : copyright Peter Lambooij
// Description : Example code EMB1-C++ week 1
//
//				 Chapter 3 van the study book (Gaddis et al.):
//				 	 cin, cout, getline, cin.getc(), cin.ignore(), endl
//
//				 Chapter 7 of the book :
//					 Classes with constructor and member functions
//					 (properties like in C# do not exist in C++,
//					  and there is always a split-up in header and source file)
//
//				 Parameter passing is shown in C# style, as taught in PCSx courses.
//				 In the next example project another way of passing will be shown: "call-by-reference".
//============================================================================
#include "Meetserie.h"
#include <iostream>

#include <string>    // C++ has a so-called string class that resembles the C# String/string classes.
using namespace std; // These two lines (#include and using) are necessary to be able to use the C++ string class.

void showMenu( void )
{
	cout << ("\nMEETSERIE MENU");
	cout << ("\n===========================");
	cout << ("\n[1] Tonen alle waarden");
	cout << ("\n[2] Toevoegen van een meetwaarde");
	cout << ("\n[3] Testen of er nog meetwaarden geplaatst kunnen worden");
	cout << ("\n[4] Tonen hoevaak een bepaalde meetwaarde voorkomt");
	cout << ("\n[5] Tonen van de naam van de meetserie");
	cout << ("\n[6] Aanpassen van de naam van de meetserie");
	cout << ("\n[7] Testen of een meetwarde voorkomt");
	cout << ("\n[8] Toevoegen  van de meetserie m1 met waarden 8 en 9");
	cout << ("\n[9] Toevoegen van de meetserieExtra mx1 met waarden -2 en -3");
	cout << ("\n[A] Tonen van het aantal verschillende waarden");
	cout << ("\n[B] Tonen hoevaak een bepaalde meetwaarde voorkomt");
	cout << ("\n[C] STOPPEN");
	cout <<  ("\n\nChoice : ");
}

int main( void )
{
	string name = "";
	bool quit = false;
	char choice = '\0';
	//int amount = 0;

	Meetserie myMeetserie("Henk");

	while (!quit)
	{
		showMenu();
		cin.get(choice);    // C++ style i/o: chapter 3 in book
        cin.ignore();       // C++ style i/o: chapter 3 in book

		switch (choice)
		{
			case '1' :
				{
					int aantalMeetwaarde = 0;
					myMeetserie.bepAantalMeetwaarden(aantalMeetwaarde);
					int i = 0;
					for (; i < aantalMeetwaarde; i++)
					{
						cout << endl << i << ", " << myMeetserie.getMeetwaarde(i) << endl;
					}
				}
				break;
			case '2' :
				{
					if (myMeetserie.isVol())
					{
						cout << "De meetserie is vol" << endl;
					}
					else
					{
						cout << "\nVoer een nieuwe waarde in: ";
						int newValue = 0;
						cin >> newValue;
						cin.ignore();
						myMeetserie.voegToe(newValue);
						cout << endl;
					}
				}
				break;
			case '3' :
				if (myMeetserie.isVol())
				{
					cout << endl << "De meetserie is vol" << endl;
				}
				else
				{
					cout << endl << "De meetserie is nog niet vol" << endl;
				}
				break;
			case '4' :
				{
					int zoekWaarde = 0;
					cout << endl << "Welke waarde zoek je? ";
					cin >> zoekWaarde;
					cin.ignore();
					int aantalMeetwaarden = 0;
					myMeetserie.bepAantalMeetwaarden(aantalMeetwaarden);
					int i = 0;
					int aantalGevonden = 0;
					for (; i < aantalMeetwaarden; i++)
					{
						if (myMeetserie.getMeetwaarde(i) == zoekWaarde)
						{
							aantalGevonden++;
						}
					}
					cout << endl << "Aantal waarde gevonden: " << aantalGevonden << endl;
				}
			    break;
			case '5' :
				cout << "naam van de meetserie" << myMeetserie.getNaam() << endl;
				 break;
			case '6' :
				{
					cout << "Geef een nieuwe naam op:" << endl;
					string input = "";
					cin >> input;
					cin.ignore();
					myMeetserie.setNaam(input);
					break;
				}
			case '7' :
				{
					int testMeetwaarde = 0;
					cout << "Voer een waarde in: ";
					cin >> testMeetwaarde;
					cin.ignore();
					if (myMeetserie.meetwaardeKomtVoor(testMeetwaarde))
					{
						cout << endl << "De waarde " << testMeetwaarde << " bestaat." << endl;
					}
					else
					{
						cout << endl << "De waarde " << testMeetwaarde << " bestaat niet." << endl;
					}
				}
				break;
			case '8' :
				//testen of iets voorkomt
				break;
			case '9' :
				//testen of iets voorkomt
				break;
			case 'A' :
				//testen of iets voorkomt
				break;
			case 'B' :
				//testen of iets voorkomt
				break;
			case 'C' :
				quit = true;
				break;
			default:
				cout << "\n\nI am terribly sorry for not understanding choice: " << choice;
				break;
		}
	}



	return 0;
}