#ifndef Plansza_h
#define Plansza_h
class Plansza
{
public:
	//konstruktor domy�lny
	Plansza();
private:
	//wypisanie planszy 6 x 6
	void wypisanie_planszy();
	//wypisanie planszy podzielonej na 4 ponumerowane �wiartki
	void wypisanie_cwiartek();
	//sprawdzenie czy kt�ry� z graczy wygra�
	int sprawdzenie();
	//tablica adres�w typu int
	int* plansza[6][6];
	//tablice przechowuj�ce warto�ci typu int
	int cwiartka1[3][3];
	int cwiartka2[3][3];
	int cwiartka3[3][3];
	int cwiartka4[3][3];
	friend class Gracz;
	friend class Rozgrywka;
};
#endif // !Plansza_h

