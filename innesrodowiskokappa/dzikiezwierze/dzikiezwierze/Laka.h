#ifndef LAKA_H
#define LAKA_H


#include <ctime>
#include <random>
#include "Pole.h"

class Laka: public Pole
{
private:
protected:

	float laka;
	void ustaw_zasob();
	void ustaw_zasob(float nowa_laka);
public:
	Laka();
	void uzyj_zasob(Stworzenie* zwierze);
	float get_laka();
};

#endif
