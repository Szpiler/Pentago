#ifndef Gracz_h
#define Gracz_h
class Gracz {
public:
	Gracz();
	Gracz(int);
	virtual void ruch(Plansza*);
	int get_pionek();
private:
	int pionek;
protected:
	void obrot_cwiartki(Plansza*, int, char);
};
#endif // !Gracz_h
