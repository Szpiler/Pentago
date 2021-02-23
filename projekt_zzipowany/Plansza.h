#ifndef Plansza_h
#define Plansza_h
class Plansza
{
public:
	Plansza();
private:
	void wypisanie_planszy();
	void wypisanie_cwiartek();
	int sprawdzenie();
	int* plansza[6][6];
	int cwiartka1[3][3];
	int cwiartka2[3][3];
	int cwiartka3[3][3];
	int cwiartka4[3][3];
	friend class Gracz;
	friend class Rozgrywka;
};
#endif // !Plansza_h

