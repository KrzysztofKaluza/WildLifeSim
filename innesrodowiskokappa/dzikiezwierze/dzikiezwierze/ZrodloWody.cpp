#include "ZrodloWody.h"

ZrodloWody::ZrodloWody()
{
	int ile_zasobu = rand() % 120;
	this->ustaw_zasob(ile_zasobu);
	this->rodzaj_pola = Typ_pola::ZRODLO_WODY;
}

void ZrodloWody::ustaw_zasob()
{
	this->woda = 0;
}

void ZrodloWody::ustaw_zasob(int nowa_woda)
{
	this->woda = nowa_woda;
}

int ZrodloWody::uzyj_zasob(int woda)
{
	this->woda = this->woda - woda;
	if (this->woda < 0) {
		woda = woda + this->woda;
		this->woda = 0;
	}
	return woda;
}

int ZrodloWody::get_zasob()
{
	return this->woda;
}


