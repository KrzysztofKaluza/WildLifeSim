#include "ZrodloWody.h"

ZrodloWody::ZrodloWody()
{
	float ile_zasobu = rand() % 120;
	this->ustaw_zasob(ile_zasobu);
	this->rodzaj_pola = "woda";
}

void ZrodloWody::ustaw_zasob()
{
	this->woda = 0;
}

void ZrodloWody::ustaw_zasob(float nowa_woda)
{
	this->woda = nowa_woda;
}

void ZrodloWody::uzyj_zasob(Stworzenie* zwierze)
{
	
}

float ZrodloWody::get_woda()
{
	return this->woda;
}
