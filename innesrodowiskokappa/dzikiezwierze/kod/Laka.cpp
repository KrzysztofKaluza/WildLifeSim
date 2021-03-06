#include "Laka.h"

Laka::Laka()
{
	/*Konstruktor*/
	int ile_zasobu = rand() % 90;
	this->ustaw_zasob(ile_zasobu);
	this->rodzaj_pola = Typ_pola::LAKA;
}

void Laka::ustaw_zasob()
{
	this->laka = 0;
}

void Laka::ustaw_zasob(int nowa_laka)
{
	/*ustawia wartosc zasobu*/
	this->laka = nowa_laka;
}

int Laka::uzyj_zasob(int zasob)
{
	/*funkcja wywolywana w zwierzeciu do przekazania zasobu*/
	this->laka = this->laka - zasob;
	if (this->laka < 0) {
		zasob = zasob + this->laka;
		this->laka = 0;
	}
	return zasob;
}

int Laka::get_zasob()
{
	/*zwraca informację o ilości zasobu*/
	return laka;
}


