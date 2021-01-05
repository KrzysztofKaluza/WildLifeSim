#ifndef ZRODLOWODY_H
#define ZRODLOWODY_H
#include "Pole.h"

#include <ctime>
#include <random>

class ZrodloWody: public Pole
{
private:
protected:
	float woda;
	void ustaw_zasob();
	void ustaw_zasob(float nowa_woda);
public:
	ZrodloWody();
	void uzyj_zasob(Stworzenie* zwierze);
	float get_woda();
};

#endif

