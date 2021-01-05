#ifndef STWORZENIE_H
#define STWORZENIE_H

#include <string>

using namespace std;
struct Pozycja {
	int x;
	int y;
};

enum State{odpoczynek=0, przemieszczanie, jedzenie, picie};

class Stworzenie
{
private:
protected:
	
	Pozycja pozycja;
	string nazwa_stworzenia;
	int HP;
	int glod;
	int szybkosc;
	int pragnienie;
	int obrazenia;
	int prog_szukania_pozywienia;
	int prog_szukania_wody;
	bool czy_zyje;
	State stan;
	string na_jakim_polu_stoi;
public:
	Stworzenie();
	//virtual void szukanie_pozywienia();
	//virtual void zmiana_glodu();
	//virtual void zmiana_pozywienia();
	virtual void update();
	virtual void maszyna_stanow();
	State getStan();
	void setNazwa_stworzenia(string nazwa);
	string getNazwa_stworzenia();
	int getHP();
	int getGlod();
	int getPragnienie();
	int getSzybkosc();
	int getObrazenia();
	int getProg_szukania_pozywienia();
	int getProg_szukania_wody();
	int getPozycja_x();
	int getPozycja_y();
	bool getCzy_zyje();
	void wczytaj_pole(string);
};
#endif
