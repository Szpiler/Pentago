#ifndef Gracz_h
#define Gracz_h
class Gracz {
public:
	//konstruktor domyœlny
	Gracz();
	//konstruktor wywo³ywany dla drugiego gracza
	Gracz(int);
	//ruch gracza 
	virtual void ruch(Plansza*);
	//geter do wartoœci przechowywanej w polu pionek
	int get_pionek();
private:
	//pole przechowuj¹ce rodzaj pionka
	int pionek;
protected:
	//obrócenie æwiartek planszy 
	void obrot_cwiartki(Plansza*, int, char);
};
#endif // !Gracz_h
