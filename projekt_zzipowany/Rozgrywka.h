#ifndef Rozgrywka_h
#define Rozgrywka_h

class Rozgrywka : public Gracz {
public:
	Rozgrywka();
	void rozgrywka(Plansza*);//ca³a rozgrywka
private:
	int pionek;
	Rozgrywka(Gracz*);
	void ruch(Plansza*);//ruch komputera
	void zapis(int, int, Plansza*);
	int odczyt(Plansza*, Gracz**, Gracz**);
};
#endif // !Rozgrywka_h


