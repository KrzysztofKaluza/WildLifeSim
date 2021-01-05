#ifndef KRZEWOWOCOWY_H
#define KRZEWOWOCOWY_H

#include <ctime>
#include <random>

#include "Pole.h"

class KrzewOwocowy : public Pole
{
private:
protected:
	int owoc;
	void ustaw_zasob();
	void ustaw_zasob(int nowy_owoc);
public:
	KrzewOwocowy();
	
	int uzyj_zasob(int owoc);
	int get_zasob();
};
#endif



