#ifndef ROSLINOZERCA_H
#define ROSLINOZERCA_H

#include "Stworzenie.h"

class Roslinozerca : public Stworzenie
{

public:
	Roslinozerca(string name, int pozycja_x, int pozycja_y, string rodzaj_pola);
	//void zmiana_pozywienia();
	//void szukanie_pozywienia();
	//void zmiana_glodu();

	void glodnienie();
	void dehydracja();

	void update();
	void maszyna_stanow();
	void czesc_operacyjna();
};

#endif

