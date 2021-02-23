#ifndef wysrodkowanie_h
#define wysrodkowanie_h
#include<iostream>

using namespace std;

//szablon funkcji wyœrodkowuj¹cej tekst w konsoli o rozmiarze 80
template <typename T1, typename T2>
void wysrodkuj(T1* tekst, T2 rozmiar)
{
	//ustawienie cout na œrodku
	if (rozmiar % 2 == 0)
		cout.width(40 - (rozmiar / 2));
	else
		cout.width(40 - ((rozmiar - 1) / 2));
	//wypisanie tekstu na œrodku konsoli
	for (int i = 0; i < rozmiar; i++)
	{
		cout << tekst[i];
	}
	cout << endl << endl;
}
#endif // !wysrodkowanie_h

