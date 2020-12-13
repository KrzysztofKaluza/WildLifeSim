#ifndef PLANSZA_H
#define PLANSZA_H
#include <vector>
#include <iostream>

#include "Laka.h"
#include "KrzewOwocowy.h"
#include "ZrodloWody.h"

#include "Miesozerca.h"
#include "Roslinozerca.h"

class Plansza
{
private:
	std::vector<std::vector<Pole*>> plansza;
	std::vector<Stworzenie*> zwierzeta;
	int rozmiar_pola;
	int rozmiar_planszy_x;
	int rozmiar_planszy_y;
protected:
	string roslinozerca = "roslinozerca";
	string miesozerca = "miesozerca";
	int martwi_roslinozercy;
	int martwi_miesozercy;
public:
	
	Plansza();
	~Plansza();
	void generuj_plansze(int rozmiar_x, int rozmiar_y);
	void ekosystem(); //co to ma robiæ?
	void update();
	void zlicz_martwe_zwierzeta();
	int getMartwi_roslinozercy();
	int getMartwi_miesozercy();
};

#endif

