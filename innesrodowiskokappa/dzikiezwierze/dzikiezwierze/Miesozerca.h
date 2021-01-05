#ifndef MIESOZERCA_H
#define MIESOZERCA_H

#include "Stworzenie.h"

class Miesozerca : public Stworzenie
{
	int prog_ataku_miesozercow;
	Stworzenie* najblizsza_ofiara_zwierze;
	Stworzenie* najblizsza_ofiara_roslinozerca;
public:
	Miesozerca(int id_zwierza, string nazwa, int pozycja_x, int pozycja_y, Pole* pole,
		int maxObszarX, int maxObszarY);
	void update();
	void maszyna_stanow();
	void glodnienie();
	void dehydracja();
	void czesc_operacyjna();
	void setNajblizsza_ofiara_zwierze(Stworzenie* zwierz);
	void setNajblizsza_ofiara_roslinozerca(Stworzenie* roslinozerca);
	void ruch(float kierunek);
};

#endif

