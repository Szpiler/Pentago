#ifndef Gracz_h
#define Gracz_h
class Gracz {
public:
	//konstruktor domy�lny
	Gracz();
	//konstruktor wywo�ywany dla drugiego gracza
	Gracz(int);
	//ruch gracza 
	virtual void ruch(Plansza*);
	//geter do warto�ci przechowywanej w polu pionek
	int get_pionek();
private:
	//pole przechowuj�ce rodzaj pionka
	int pionek;
protected:
	//obr�cenie �wiartek planszy 
	void obrot_cwiartki(Plansza*, int, char);
};
#endif // !Gracz_h
