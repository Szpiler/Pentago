#include "pch.h"
#include "Plansza.h"
#include "Gracz.h"
#include "Rozgrywka.h"
#include "wysrodkowanie.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

Rozgrywka::Rozgrywka() :pionek(0) {}
Rozgrywka::Rozgrywka(Gracz* g) {
	if (g->get_pionek() == 1)
		pionek = 2;
	else if (g->get_pionek() == 2)
		pionek = 1;
	else
		pionek = 0;
}
void Rozgrywka::ruch(Plansza* p1) {
	srand((unsigned)time(NULL));
	int a, b;
	bool czujka = true;
	int numer(0);
	char kierunek_obrotu;
	p1->wypisanie_planszy();
	while (czujka)
	{
		b = rand() % 6;
		a = rand() % 6;
		if (*p1->plansza[b][a] != 0)
			;
		else
			czujka = false;
	}
	*p1->plansza[b][a] = pionek;
	numer = rand() % 4 + 1;
	a = rand() % 2;
	if (a == 0)
		kierunek_obrotu = 'L';
	else
		kierunek_obrotu = 'P';
	obrot_cwiartki(p1, numer, kierunek_obrotu);
	p1->wypisanie_planszy();
}
void Rozgrywka::zapis(int pion1, int pion2, Plansza* p1) {
	string nazwa;
	ofstream zapis("wyniki.txt", ios_base::app);
	cout << endl << "Podaj nazwe zapisu: ";
	getline(cin, nazwa);
	zapis << nazwa << endl;
	zapis << pion1 << endl;
	zapis << pion2 << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			zapis << *p1->plansza[i][j];
			zapis << " ";
		}
		zapis << endl;
	}
	zapis.close();
}
int Rozgrywka::odczyt(Plansza *p1, Gracz **g1, Gracz **g2){
	bool otwarcie(true);
	int wyswietl(0);
	int pom1(0);
	int pom2(0);
	int zwrot(3);
	string pobrane, pom3;
	ifstream odczyt;
	pom3 = "";
	odczyt.open("wyniki.txt");
	if (!odczyt.is_open())
	{
		cout << "Nie ma zadnych zapisanych rozgrywek" << endl;
		otwarcie = false;
		zwrot = 0;
	}
	if (otwarcie)
	{
		cout << "Wybierz rozgrywke do wczytania wybierajac odpowiadajaca mu liczbe:" << endl;
		while (!odczyt.eof())
		{
			getline(odczyt, pobrane);
			if ((wyswietl + 9) % 9 == 0 && pobrane.compare(pom3) != 0)
				cout << (wyswietl + 9) / 9 << " - " << pobrane << endl;
			wyswietl++;
		}
		odczyt.close();
		while (pom1 > (wyswietl - 1) / 9 || pom1 < 1)
		{
			cin >> pom1;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
			while (getchar() != '\n')
				;
		}
		odczyt.open("wyniki.txt");
		while ((pom2 + 9) / 9 != pom1)
		{
			getline(odczyt, pobrane);
			pom2++;
		}
		getline(odczyt, pobrane);
		pom2 = 0;
		odczyt >> pom2;
		*g1 = new Gracz(pom2);
		odczyt >> pom2;
		if (pom2 == 0)
		{
			*g2 = new Rozgrywka(*g1);
			zwrot = 4;
		}
		else
			*g2 = new Gracz(pom2);
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				odczyt >> pom2;
				*p1->plansza[i][j] = pom2;
			}
		}
	}
	odczyt.close();
	return zwrot;
}
void Rozgrywka::rozgrywka(Plansza* p1) {
	Gracz *g1, *g2;
	g1 = NULL;
	g2 = NULL;
	bool czujka(true);
	int koniec(0);
	int wybor(0);
	int numer_tury(0);
	char czyzap('a');
	char znak('a');
	char komunikat[60];
	while (znak != 't' && znak != 'T' && znak != 'n' && znak != 'N')
	{
		cout << "Czy chcesz wczytac zapisana gre? (T - tak, N - nie): ";
		cin >> znak;
		while (getchar() != '\n')
			;
	}
	if (znak == 't' || znak == 'T')
	{
		wybor = odczyt(p1, &g1, &g2);
		if (wybor != 0)
		{
			cout << "Wczytanie gry powiodlo sie" << endl;
			czujka = false;
		}
	}
	while (wybor != 1 && wybor != 2 && czujka)
	{
		cout << "Wybierz tryb gry:" << endl << "1 - gracz vs gracz" << endl << "2 - gracz vs komputer" << endl;
		cout << "Wybierz 1 lub 2: ";
		cin >> wybor;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		while (getchar() != '\n')
			;
		cout << endl;
	}
	if (wybor == 1)
	{
		int pom(0);
		while (pom != 1 && pom != 2)
		{
			cout << "Gracz 1 wybiera rodzaj pionka:" << endl << "1 - O" << endl << "2 - X" << endl;
			cout << "Wybierz 1 lub 2: ";
			cin >> pom;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
			while (getchar() != '\n')
				;
		}
		if (pom == 1)
		{
			g1 = new Gracz(1);
			g2 = new Gracz(2);
		}
		else
		{
			g1 = new Gracz(2);
			g2 = new Gracz(1);
		}
		while (koniec == 0 && numer_tury != 36)
		{
			czyzap = 'a';
			while (czyzap != 'T' && czyzap != 't' && czyzap != 'N' && czyzap != 'n')
			{
				cout << "Czy chcesz zapisac stan gry?" << endl << "Jesli tak - T, jesli nie - N: ";
				cin >> czyzap;
				while (getchar() != '\n')
					;
			}
			if (czyzap == 'T' || czyzap == 't')
			{
				int pion1, pion2;
				pion1 = g1->get_pionek();
				pion2 = g2->get_pionek();
				zapis(pion1, pion2, p1);
			}
			cout << "Ruch Gracza 1: ";
			numer_tury++;
			g1->ruch(p1);
			koniec = p1->sprawdzenie();
			if (koniec != 0)
				break;
			cout << "Ruch Gracza 2: ";
			numer_tury++;
			g2->ruch(p1);
			koniec = p1->sprawdzenie();
		}
	}
	else if (wybor == 2)
	{
		int pom(0);
		while (pom != 1 && pom != 2)
		{
			cout << "Wybierz rodzaj pionka:" << endl << "1 - O" << endl << "2 - X" << endl;
			cout << "Wybierz 1 lub 2: ";
			cin >> pom;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
			while (getchar() != '\n')
				;
		}
		if (pom == 1)
		{
			g1 = new Gracz(1);
			g2 = new Rozgrywka(g1);
		}
		else
		{
			g1 = new Gracz(2);
			g2 = new Rozgrywka(g1);
		}
		while (koniec == 0 && numer_tury != 36)
		{
			czyzap = 'a';
			while (czyzap != 'T' && czyzap != 't' && czyzap != 'N' && czyzap != 'n')
			{
				cout << "Czy chcesz zapisac stan gry?" << endl << "Jesli tak - T, jesli nie - N: ";
				cin >> czyzap;
				while (getchar() != '\n')
					;
			}
			if (czyzap == 'T' || czyzap == 't')
			{
				int pion1, pion2;
				pion1 = g1->get_pionek();
				pion2 = 0;
				zapis(pion1, pion2, p1);
			}
			cout << "Ruch Gracza 1: ";
			numer_tury++;
			g1->ruch(p1);
			koniec = p1->sprawdzenie();
			if (koniec != 0)
				break;
			cout << "Ruch Komputera: ";
			numer_tury++;
			g2->ruch(p1);
			koniec = p1->sprawdzenie();
		}
	}
	else if (wybor == 3)
	{
		while (koniec == 0 && numer_tury != 36)
		{
			czyzap = 'a';
			while (czyzap != 'T' && czyzap != 't' && czyzap != 'N' && czyzap != 'n')
			{
				cout << "Czy chcesz zapisac stan gry?" << endl << "Jesli tak - T, jesli nie - N: ";
				cin >> czyzap;
				while (getchar() != '\n')
					;
			}
			if (czyzap == 'T' || czyzap == 't')
			{
				int pion1, pion2;
				pion1 = g1->get_pionek();
				pion2 = g2->get_pionek();
				zapis(pion1, pion2, p1);
			}
			cout << "Ruch Gracza 1: ";
			numer_tury++;
			g1->ruch(p1);
			koniec = p1->sprawdzenie();
			if (koniec != 0)
				break;
			cout << "Ruch Gracza 2: ";
			numer_tury++;
			g2->ruch(p1);
			koniec = p1->sprawdzenie();
		}
	}
	else if(wybor == 4)
	{
		while (koniec == 0 && numer_tury != 36)
		{
			czyzap = 'a';
			while (czyzap != 'T' && czyzap != 't' && czyzap != 'N' && czyzap != 'n')
			{
				cout << "Czy chcesz zapisac stan gry?" << endl << "Jesli tak - T, jesli nie - N: ";
				cin >> czyzap;
				while (getchar() != '\n')
					;
			}
			if (czyzap == 'T' || czyzap == 't')
			{
				int pion1, pion2;
				pion1 = g1->get_pionek();
				pion2 = 0;
				zapis(pion1, pion2, p1);
			}
			cout << "Ruch Gracza 1: ";
			numer_tury++;
			g1->ruch(p1);
			koniec = p1->sprawdzenie();
			if (koniec != 0)
				break;
			cout << "Ruch Komputera: ";
			numer_tury++;
			g2->ruch(p1);
			koniec = p1->sprawdzenie();
		}
	}
	cout << endl << endl << endl;
	if (koniec == 1)
	{
		if (pionek == 1)
		{
			strcpy(komunikat, "- - - - - - - - - - Komputer wygral!!! - - - - - - - - - -");
			wysrodkuj<char, int>(komunikat, 58);
		}
		else if (g1->get_pionek() == 1)
		{
			strcpy(komunikat, "- - - - - - - - - - Gracz 1 wygral!!! - - - - - - - - - -");
			wysrodkuj(komunikat, 57);
		}
		else
		{
			strcpy(komunikat, "- - - - - - - - - - Gracz 2 wygra³!!! - - - - - - - - - -");
			wysrodkuj(komunikat, 57);
		}
	}
	else if (koniec == 2)
	{
		if (pionek == 2)
		{
			strcpy(komunikat, "- - - - - - - - - - Komputer wygral!!! - - - - - - - - - -");
			wysrodkuj(komunikat, 58);
		}
		else if (g1->get_pionek() == 2)
		{
			strcpy(komunikat, "- - - - - - - - - - Gracz 1 wygral!!! - - - - - - - - - -");
			wysrodkuj(komunikat, 57);
		}
		else
		{
			strcpy(komunikat, "- - - - - - - - - - Gracz 2 wygra³!!! - - - - - - - - - -");
			wysrodkuj(komunikat, 57);
		}
	}
	else
	{
		strcpy(komunikat, "- - - - - - - - - - Remis!!! - - - - - - - - - -");
		wysrodkuj(komunikat, 48);
	}
	strcpy(komunikat, ">>>>>>>>>>>>>>>>>>>>> KONIEC GRY <<<<<<<<<<<<<<<<<<<<<");
	wysrodkuj(komunikat, 54);
	cout << endl << endl;
	delete g1;
	delete g2;
}
