#include "KrzewOwocowy.h"

KrzewOwocowy::KrzewOwocowy()
{
	/*Konstruktor*/
	int ile_zasobu = rand() % 120;
	this->ustaw_zasob(ile_zasobu);
	this->rodzaj_pola = Typ_pola::KRZEW_OWOCOWY;
}

void KrzewOwocowy::ustaw_zasob()
{
	this->owoc = 0;
}

void KrzewOwocowy::ustaw_zasob(int nowy_owoc)
{
	/*ustawia wartosc zasobu*/
	this->owoc = nowy_owoc;
}

int KrzewOwocowy::uzyj_zasob(int owoc)
{
	/*funkcja wywolywana w zwierzeciu do przekazania zasobu*/
	this->owoc = this->owoc - owoc;
	if (this->owoc < 0) {
		owoc = owoc + this->owoc;
		this->owoc = 0;
	}
	return owoc;
}

int KrzewOwocowy::get_zasob()
{
	/*zwraca informację o ilości zasobu*/
	return this->owoc;
}
