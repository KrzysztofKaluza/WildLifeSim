#include "KrzewOwocowy.h"

KrzewOwocowy::KrzewOwocowy()
{
	float ile_zasobu = rand() % 120;
	this->ustaw_zasob(ile_zasobu);
	this->rodzaj_pola = "krzew";
}

void KrzewOwocowy::ustaw_zasob()
{
	this->owoc = 0;
}

void KrzewOwocowy::ustaw_zasob(float nowy_owoc)
{
	this->owoc = nowy_owoc;
}

void KrzewOwocowy::uzyj_zasob(Stworzenie* zwierze)
{

}

float KrzewOwocowy::get_owoc()
{
	return this->owoc;
}
