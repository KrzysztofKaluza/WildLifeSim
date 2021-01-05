#ifndef ROSLINOZERCA_H
#define ROSLINOZERCA_H

#include "Stworzenie.h"

class Roslinozerca : public Stworzenie
{
	
public:
	Roslinozerca(int id_zwierza, string name, int pozycja_x, int pozycja_y, Pole* pole,
		int maxObszarX, int maxObszarY);
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

