#include "Laka.h"

Laka::Laka()
{
	float ile_zasobu = rand() % 90;
	this->ustaw_zasob(ile_zasobu);
	this->rodzaj_pola = "laka";
}

void Laka::ustaw_zasob()
{
	this->laka = 0;
}

void Laka::ustaw_zasob(float nowa_laka)
{
	this->laka = nowa_laka;
}

void Laka::uzyj_zasob(Stworzenie* zwierze)
{
	
}

float Laka::get_laka()
{
	return this->laka;
}
