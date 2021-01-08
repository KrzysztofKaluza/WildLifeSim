#include "ZrodloWody.h"

ZrodloWody::ZrodloWody()
{
	/*Konstruktor*/
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
	/*ustawia wartosc zasobu*/
	this->woda = nowa_woda;
}

int ZrodloWody::uzyj_zasob(int zasob)
{
	/*funkcja wywolywana w zwierzeciu do przekazania zasobu*/
	this->woda = this->woda - zasob;
	if (this->woda < 0) {
		zasob = zasob + this->woda;
		this->woda = 0;
	}
	return zasob;
}

int ZrodloWody::get_zasob()
{
	/*zwraca informację o ilości zasobu*/
	return this->woda;
}


