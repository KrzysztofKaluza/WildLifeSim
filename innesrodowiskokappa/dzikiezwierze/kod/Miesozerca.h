#ifndef MIESOZERCA_H
#define MIESOZERCA_H

#include <math.h>
#include "Stworzenie.h"

class Miesozerca : public Stworzenie
{
	
public:
	Miesozerca(int id_zwierza, string nazwa, int pozycja_x, int pozycja_y, Pole* pole,
		int maxObszarX, int maxObszarY);
	void update();
	void maszyna_stanow();
	void glodnienie();
	void dehydracja();
	void czesc_operacyjna();
	void ruch(float kierunek);
};

#endif

