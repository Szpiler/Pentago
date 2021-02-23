#ifndef Plansza_h
#define Plansza_h
class Plansza
{
public:
	//konstruktor domyœlny
	Plansza();
private:
	//wypisanie planszy 6 x 6
	void wypisanie_planszy();
	//wypisanie planszy podzielonej na 4 ponumerowane æwiartki
	void wypisanie_cwiartek();
	//sprawdzenie czy któryœ z graczy wygra³
	int sprawdzenie();
	//tablica adresów typu int
	int* plansza[6][6];
	//tablice przechowuj¹ce wartoœci typu int
	int cwiartka1[3][3];
	int cwiartka2[3][3];
	int cwiartka3[3][3];
	int cwiartka4[3][3];
	friend class Gracz;
	friend class Rozgrywka;
};
#endif // !Plansza_h

