#ifndef KRZEWOWOCOWY_H
#define KRZEWOWOCOWY_H

#include <ctime>
#include <random>

#include "Pole.h"

class KrzewOwocowy : public Pole
{
private:
protected:
	float owoc;
	void ustaw_zasob();
	void ustaw_zasob(float nowy_owoc);
public:
	KrzewOwocowy();
	
	void uzyj_zasob(Stworzenie* zwierze);
	float get_owoc();
};
#endif



