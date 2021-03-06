// Projekt_Pentago.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Plansza.h"
#include "Gracz.h"
#include "Rozgrywka.h"
#include "wysrodkowanie.h"

using namespace std;


int main()
{
	//tworzenie planszy
	Plansza p1;
	//tworzenie rozgrywki
	Rozgrywka r1;
	char autor[40] = {"Autor programu: Piotr Jaworski"};
	char pentago[10] = { "PENTAGO" };
	int id[6] = { 1, 1, 0, 4, 2, 4 };
	//wypisanie wyśrodkowanego napisu PENTAGO
	wysrodkuj<char, int>(pentago, 10);
	//przeprowadzenie rozgrywki
	r1.rozgrywka(&p1);
	//wypisanie wyśrodkowanych danych twórcy gry
	wysrodkuj(autor, 30);
	////wypisanie wyśrodkowanego indeksu twórcy gry
	wysrodkuj<int, int>(id, 6);
	return 0;
}


