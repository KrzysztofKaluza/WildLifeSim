#ifndef LAKA_H
#define LAKA_H


#include <ctime>
#include <random>
#include "Pole.h"

class Laka: public Pole
{
private:
protected:

	int laka;
	void ustaw_zasob();
	void ustaw_zasob(int nowa_laka);
public:
	Laka();
	int uzyj_zasob(int laka);
	int get_zasob();
};

#endif
