#ifndef PLANSZA_H
#define PLANSZA_H

#define ILE_ZWIERZAT 8
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
	Stworzenie* tablica_najblizszych_zwierzat[ILE_ZWIERZAT];
	int rozmiar_pola;
	int rozmiar_planszy_x;
	int rozmiar_planszy_y;
protected:
	string roslinozerca = "roslinozerca";
	string miesozerca = "miesozerca";
	int martwi_roslinozercy;
	int martwi_miesozercy;
	int ilosc_roslinozercow;
public:
	
	Plansza();
	~Plansza();
	void generuj_plansze(int rozmiar_x, int rozmiar_y);
	void ekosystem(); //co to ma robiæ?
	void update();
	void zlicz_martwe_zwierzeta();
	int getMartwi_roslinozercy();
	int getMartwi_miesozercy();
	int getIlosc_roslinozercow();
	
	void znajdz_najblizsze_siebie_zwierzeta();
	
};

#endif

