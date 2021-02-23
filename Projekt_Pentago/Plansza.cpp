#include "pch.h"
#include "Plansza.h"
#include<iostream>

using namespace std;

//konstruktor domyœlny 
Plansza::Plansza() {
	//wype³nienie æwiartek zerami
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cwiartka1[i][j] = 0;
			cwiartka2[i][j] = 0;
			cwiartka3[i][j] = 0;
			cwiartka4[i][j] = 0;
		}
	}
	//przypisanie adresów æwiartek do planszy
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i < 3 && j < 3)
				plansza[i][j] = &cwiartka1[i][j];
			else if (i < 3 && j > 2)
				plansza[i][j] = &cwiartka2[i][j - 3];
			else if (i > 2 && j < 3)
				plansza[i][j] = &cwiartka3[i - 3][j];
			else if (i > 2 && j > 2)
				plansza[i][j] = &cwiartka4[i - 3][j - 3];
		}
	}
}
//sprawdza czy któryœ z graczy wygra³
int Plansza::sprawdzenie() {
	int rezultat = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//sprawdzanie rzêdów
			if (*plansza[i][j + 1] != 0)
			{
				if (*plansza[i][j] == *plansza[i][j + 1] && *plansza[i][j + 2] == *plansza[i][j + 3] && *plansza[i][j + 4] == *plansza[i][j] && *plansza[i][j + 4] == *plansza[i][j + 2])
				{
					if (*plansza[i][j + 1] == 1 && rezultat != 1 && rezultat != 3)
						rezultat++;
					else if (*plansza[i][j + 1] == 2 && rezultat != 2 && rezultat != 3)
						rezultat += 2;
				}
			}
			//sprawdzenie kolumn
			if (*plansza[j + 1][i] != 0)
			{
				if (*plansza[j][i] == *plansza[j + 1][i] && *plansza[j + 2][i] == *plansza[j + 3][i] && *plansza[j + 4][i] == *plansza[j][i] && *plansza[j + 4][i] == *plansza[j + 2][i])
				{
					if (*plansza[j + 1][i] == 1 && rezultat != 1 && rezultat != 3)
						rezultat++;
					else if (*plansza[j + 1][i] == 2 && rezultat != 2 && rezultat != 3)
						rezultat += 2;
				}
			}
			if (i == 0)
			{
				//sprawdzenie przêk¹tnej od [0][0] do [5][5]
				if (*plansza[j + 1][j + 1] != 0)
				{
					if (*plansza[j][j] == *plansza[j + 1][j + 1] && *plansza[j + 2][j + 2] == *plansza[j + 3][j + 3] && *plansza[j + 4][j + 4] == *plansza[j][j] && *plansza[j + 4][j + 4] == *plansza[j + 2][j + 2])
					{
						if (*plansza[j + 1][j + 1] == 1 && rezultat != 1 && rezultat != 3)
							rezultat++;
						else if (*plansza[j + 1][j + 1] == 2 && rezultat != 2 && rezultat != 3)
							rezultat += 2;
					}
				}
				//sprawdzenie  przek¹tnej od [5][0] do [0][5]
				if (*plansza[j + 3][2 - j] != 0)
				{
					if (*plansza[j + 4][1 - j] == *plansza[j + 3][2 - j] && *plansza[j + 2][3 - j] == *plansza[j + 1][4 - j] && *plansza[j][5 - j] == *plansza[j + 4][1 - j] && *plansza[j][5 - j] == *plansza[j + 2][3 - j])
					{
						if (*plansza[j + 3][2 - j] == 1 && rezultat != 1 && rezultat != 3)
							rezultat++;
						else if (*plansza[j + 3][2 - j] == 2 && rezultat != 2 && rezultat != 3)
							rezultat += 2;
					}
				}
				//sprawdzenie przek¹tnych od [0][1] do [4][5] i od [1][0] do [5][4]
				if (*plansza[j + 1][2 - j] != 0)
				{
					if (*plansza[j][1 - j] == *plansza[j + 1][2 - j] && *plansza[j + 2][3 - j] == *plansza[j + 3][4 - j] && *plansza[j + 4][5 - j] == *plansza[j][1 - j] && *plansza[j + 4][5 - j] == *plansza[j + 2][3 - j])
					{
						if (*plansza[j + 1][2 - j] == 1 && rezultat != 1 && rezultat != 3)
							rezultat++;
						else if (*plansza[j + 1][2 - j] == 2 && rezultat != 2 && rezultat != 3)
							rezultat += 2;
					}
				}
				//sprawdzenie przek¹tnych od [0][4] do [4][0] i od [1][5] do [5][1]
				if (*plansza[j + 1][j + 3] != 0)
				{
					if (*plansza[j][j + 4] == *plansza[j + 1][j + 3] && *plansza[j + 2][j + 2] == *plansza[j + 3][j + 1] && *plansza[j + 4][j] == *plansza[j][j + 4] && *plansza[j + 4][j] == *plansza[j + 2][j + 2])
					{
						if (*plansza[j + 1][j + 3] == 1 && rezultat != 1 && rezultat != 3)
							rezultat++;
						else if (*plansza[j + 1][j + 3] == 2 && rezultat != 2 && rezultat != 3)
							rezultat += 2;
					}
				}
			}
		}
	}
	return rezultat;
}
//wypisuje ca³¹ plansze 6 x 6
void Plansza::wypisanie_planszy() {
	char litera = 'A';
	int pom1 = 1;
	cout << endl << endl;
	for (int i = 0; i < 14; i++)
	{
		int pom2 = 3;
		for (int j = 0; j < 27; j++)
		{
			if (i == 0)
			{
				if (j != 0 && j % 4 == 0)
				{
					cout << j - pom2;
					pom2 += 3;
				}
				else
					cout << " ";
			}
			else if (i % 2 != 0)
			{
				if (j < 3 || j % 4 == 2)
					cout << " ";
				else
					cout << "-";
			}
			else
			{
				if (j == 0)
				{
					cout << litera;
					litera++;
				}
				else if (j % 2 != 0)
					cout << " ";
				else if ((j - 2) % 4 == 0)
					cout << "|";
				else
				{
					if (*plansza[i - pom1 - 1][j - pom2 - 1] == 0)
						cout << " ";
					else if (*plansza[i - pom1 - 1][j - pom2 - 1] == 1)
						cout << "O";
					else if (*plansza[i - pom1 - 1][j - pom2 - 1] == 2)
						cout << "X";
					pom2 += 3;
				}
			}
		}
		cout << endl;
		if (i != 0 && i % 2 == 0)
			pom1++;
	}
}
//wypisuje plansze podzielon¹ na 4 ponumerowane æwiartki
void Plansza::wypisanie_cwiartek() {
	int pom1 = 1;
	cout << endl << endl;
	for (int i = 0; i < 14; i++)
	{
		int pom2 = 3;
		if (i == 8)
		{
			cout << endl << endl << endl;
			cout << "        3               4" << endl;
			cout << "   --- --- ---     --- --- ---" << endl;
		}
		for (int j = 0; j < 27; j++)
		{
			if (i == 0)
			{
				if (j == 8 || j == 20)
				{
					cout << j - pom2 - 4;
					pom2 += 11;
				}
				else if (j == 13)
					cout << "     ";
				else
					cout << " ";
			}
			else if (i % 2 != 0)
			{
				if (j < 3 || j % 4 == 2)
					cout << " ";
				else if (j == 13)
					cout << "-    ";
				else
					cout << "-";
			}
			else
			{
				if (j == 0)
				{
					cout << " ";
				}
				else if (j % 2 != 0 && j != 13)
					cout << " ";
				else if (j == 13)
					cout << " |   ";
				else if ((j - 2) % 4 == 0)
					cout << "|";
				else
				{
					if (*plansza[i - pom1 - 1][j - pom2 - 1] == 0)
						cout << " ";
					else if (*plansza[i - pom1 - 1][j - pom2 - 1] == 1)
						cout << "O";
					else if (*plansza[i - pom1 - 1][j - pom2 - 1] == 2)
						cout << "X";
					pom2 += 3;
				}
			}
		}
		cout << endl;
		if (i != 0 && i % 2 == 0)
			pom1++;
	}
}