#ifndef wysrodkowanie_h
#define wysrodkowanie_h
#include<iostream>

using namespace std;

template <typename T1, typename T2>
void wysrodkuj(T1* tekst, T2 rozmiar)
{
	if (rozmiar % 2 == 0)
		cout.width(40 - (rozmiar / 2));
	else
		cout.width(40 - ((rozmiar - 1) / 2));
	for (int i = 0; i < rozmiar; i++)
	{
		cout << tekst[i];
	}
	cout << endl << endl;
}
#endif // !wysrodkowanie_h

