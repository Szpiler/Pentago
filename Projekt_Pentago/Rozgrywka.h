#ifndef Rozgrywka_h
#define Rozgrywka_h

class Rozgrywka : public Gracz {
public:
	//konstruktor domyœlny
	Rozgrywka();
	//ca³a rozgrywka
	void rozgrywka(Plansza*);
private:
	//rodzaj pionka gracza
	int pionek;
	//konstruktor wykorzystywany przy grze z komputerem
	Rozgrywka(Gracz*);
	//ruch komputera
	void ruch(Plansza*);
	//zapis rozgrywki
	void zapis(int, int, Plansza*);
	//odczyt zapisanych rozgrywek
	int odczyt(Plansza*, Gracz**, Gracz**);
};
#endif // !Rozgrywka_h


