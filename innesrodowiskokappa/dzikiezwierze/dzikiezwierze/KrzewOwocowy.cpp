#include "KrzewOwocowy.h"

KrzewOwocowy::KrzewOwocowy()
{
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
	this->owoc = nowy_owoc;
}

int KrzewOwocowy::uzyj_zasob(int owoc)
{
	this->owoc = this->owoc - owoc;
	if (this->owoc < 0) {
		owoc = owoc + this->owoc;
		this->owoc = 0;
	}
	return owoc;
}

int KrzewOwocowy::get_zasob()
{
	return this->owoc;
}
