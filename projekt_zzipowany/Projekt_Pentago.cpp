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
	Plansza p1;
	Rozgrywka r1;
	char autor[40] = {"Autor programu: Piotr Jaworski"};
	char pentago[10] = { "PENTAGO" };
	int id[6] = { 1, 1, 0, 4, 2, 4 };
	wysrodkuj<char, int>(pentago, 10);
	r1.rozgrywka(&p1);
	wysrodkuj(autor, 30);
	wysrodkuj<int, int>(id, 6);
	return 0;
}


