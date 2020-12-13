#ifndef MIESOZERCA_H
#define MIESOZERCA_H

#include "Stworzenie.h"

class Miesozerca : public Stworzenie
{
	int prog_ataku_miesozercow;
public:
	Miesozerca(string nazwa, int pozycja_x, int pozycja_y, string rodzaj_pola);
	void update();
	void maszyna_stanow();
	void glodnienie();
	void dehydracja();
	void czesc_operacyjna();
};

#endif

