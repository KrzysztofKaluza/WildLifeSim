#ifndef POLE_H
#define POLE_H
#include "Stworzenie.h"

class Pole
{
protected:
	string rodzaj_pola;
public:
	virtual void ustaw_zasob() = 0;
	virtual void uzyj_zasob(Stworzenie*) = 0;
	string getRodzaj_pola();
};

#endif
