#ifndef STWORZENIE_H
#define STWORZENIE_H

#include <string>

#include "Pole.h"
#define MAX_PRAGNIENIE 100
#define MAX_GLOD 100
using namespace std;
struct Pozycja {
	int x;
	int y;
};

enum State{odpoczynek=0, przemieszczanie, polowanie, jedzenie, picie, smierc, koniec};

class Stworzenie
{
private:
protected:
	int prog_ataku_miesozercow;
	Stworzenie* najblizsza_ofiara_zwierze;
	float kierunek;
	int dystans;
	bool czy_dotarl;
	bool szuka_jedzenie;
	bool szuka_picie;
	int id_zwierzecia;
	Pozycja pozycja;
	string nazwa_stworzenia;
	int HP;
	int glod;
	int szybkosc;
	int pragnienie;
	int obrazenia;
	/*Ka�dy zwierz przenosi w sobie jak�� ilo�� mi�sa,
	kt�ra zostaje oddana do pola, gdy umrze*/
	int przenoszone_mieso; 
	int prog_szukania_pozywienia;
	int prog_szukania_wody;
	bool czy_zyje;
	int maxObszarX;
	int maxObszarY;
	State stan;
	Pole *pole_na_ktorym_stoi;
	
public:
	Stworzenie();
	virtual void update() = 0;
	virtual void maszyna_stanow() = 0;
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
	int getProg_ataku_miesozercow();
	bool getCzy_zyje();
	void wczytaj_pole(Pole* pole);
	bool czyPozaObszarem(int pos_x, int pos_y);
	virtual void setNajblizsza_ofiara_zwierze(Stworzenie* zwierz);
	void usmierc();

	
};
#endif
