#ifndef ZRODLOWODY_H
#define ZRODLOWODY_H
#include "Pole.h"

#include <ctime>
#include <random>

class ZrodloWody: public Pole
{
private:
protected:
	int woda;
	void ustaw_zasob();
	void ustaw_zasob(int nowa_woda);
public:
	ZrodloWody();
	int uzyj_zasob(int woda);
	int get_zasob();
};

#endif

