#include "pch.h"
#include "Plansza.h"
#include "Gracz.h"
#include<iostream>

using namespace std;

Gracz::Gracz(): pionek(0) {}
Gracz::Gracz(int a) {
	if (a == 1 || a == 2)
		pionek = a;
	else
		pionek = 0;
}
int Gracz::get_pionek() { return pionek; }
void Gracz::ruch(Plansza* p1) {
	int a, b;
	bool czujka = true;
	int numer = 0;
	char kierunek_obrotu = 'a';
	p1->wypisanie_planszy();
	while (czujka)
	{
		char litera;
		cout << endl << "Wybierz pole podajac odpowiadajaca mu litere i cyfre" << endl;
		cout << "Podaj litere: ";
		cin >> litera;
		while (getchar() != '\n')
			;
		cout << "Podaj cyfre: ";
		cin >> a;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		while (getchar() != '\n')
			;
		b = (int)litera;
		if (b > 96 && b < 103)
			b = b - 32;
		if (a < 1 || b < 65 || a > 6 || b > 70)
			cout << "Bledne dane. Popraw:" << endl;
		else if (*p1->plansza[b - 65][a - 1] != 0)
			cout << "To pole jest juz zajete. Wybierz inne.";
		else
			czujka = false;
	}
	*p1->plansza[b - 65][a - 1] = pionek;
	p1->wypisanie_planszy();
	cout << endl << endl;
	p1->wypisanie_cwiartek();
	while (numer < 1 || numer > 4)
	{
		cout << endl << "Wybierz cwiartke ktora chcesz obrocic: ";
		cin >> numer;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		while (getchar() != '\n')
			;
	}
	while (kierunek_obrotu != 'L' && kierunek_obrotu != 'P')
	{
		cout << endl << "Wybierz kierunek obrotu(P - prawo, L - lewo): ";
		cin >> kierunek_obrotu;
		while (getchar() != '\n')
			;
		if (kierunek_obrotu == 'p')
			kierunek_obrotu = 'P';
		else if (kierunek_obrotu == 'l')
			kierunek_obrotu = 'L';
	}
	obrot_cwiartki(p1, numer, kierunek_obrotu);
	cout << "Po obrocie: " << endl;
	p1->wypisanie_planszy();
}
void Gracz::obrot_cwiartki(Plansza* p1, int numer, char kierunek_obrotu) {
	int tab[3][3] = { {0} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (numer == 1)
				tab[i][j] = p1->cwiartka1[i][j];
			else if (numer == 2)
				tab[i][j] = p1->cwiartka2[i][j];
			else if (numer == 3)
				tab[i][j] = p1->cwiartka3[i][j];
			else
				tab[i][j] = p1->cwiartka4[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//w lewo
			if (numer == 1 && kierunek_obrotu == 'L')
				p1->cwiartka1[i][j] = tab[j][2 - i];
			else if (numer == 2 && kierunek_obrotu == 'L')
				p1->cwiartka2[i][j] = tab[j][2 - i];
			else if (numer == 3 && kierunek_obrotu == 'L')
				p1->cwiartka3[i][j] = tab[j][2 - i];
			else if (numer == 4 && kierunek_obrotu == 'L')
				p1->cwiartka4[i][j] = tab[j][2 - i];
			//w prawo
			else if (numer == 1 && kierunek_obrotu == 'P')
				p1->cwiartka1[i][j] = tab[2 - j][i];
			else if (numer == 2 && kierunek_obrotu == 'P')
				p1->cwiartka2[i][j] = tab[2 - j][i];
			else if (numer == 3 && kierunek_obrotu == 'P')
				p1->cwiartka3[i][j] = tab[2 - j][i];
			else if (numer == 4 && kierunek_obrotu == 'P')
				p1->cwiartka4[i][j] = tab[2 - j][i];
		}
	}
}