#include "pch.h"
#include "Plansza.h"
#include "Gracz.h"
#include<iostream>

using namespace std;

//konstruktor domyœlny
Gracz::Gracz(): pionek(0) {}
//konstruktor wykorzystywany przy tworzeniu drugiego gracza
Gracz::Gracz(int a) {
	if (a == 1 || a == 2)
		pionek = a;
	else
		pionek = 0;
}
//geter wartoœci znajduj¹cej siê w polu pionek
int Gracz::get_pionek() { return pionek; }
//ruch gracza
void Gracz::ruch(Plansza* p1) {
	int a, b;
	bool czujka = true;
	int numer = 0;
	char kierunek_obrotu = 'a';
	//wypisanie planszy
	p1->wypisanie_planszy();
	//wybór pola w którym gracz chce postawiæ swój pionek
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
	//ustawienie pionka w wybranym przez gracza polu
	*p1->plansza[b - 65][a - 1] = pionek;
	//wypisanie zaktualizowanej planszy 
	p1->wypisanie_planszy();
	cout << endl << endl;
	//wypisanie planszy w widoku podzielonym na æwiartki
	p1->wypisanie_cwiartek();
	//wybór æwiartki do obrotu
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
	//wybór kierunku obrotu wybranej æwiartki
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
	//obrót wybranej æwiartki w wybranym kierunku
	obrot_cwiartki(p1, numer, kierunek_obrotu);
	cout << "Po obrocie: " << endl;
	//wypisanie zaktualizowanej planszy
	p1->wypisanie_planszy();
}
//obrócenie æwiartki planszy
void Gracz::obrot_cwiartki(Plansza* p1, int numer, char kierunek_obrotu) {
	//æwiartka pomocnicza wype³niona zerami
	int tab[3][3] = { {0} };
	//skopiowanie stanu wybranej æwiartki przed obrotem
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
	//obrót wybranej æwiartki w wybranym kierunku
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