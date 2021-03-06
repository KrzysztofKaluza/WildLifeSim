#include "Pole.h"

Pole::Pole()
{
	this->mieso = 0;
}

Typ_pola Pole::getRodzaj_pola()
{
	return this->rodzaj_pola;
}

int Pole::get_mieso()
{
	return this->mieso;
}

int Pole::uzyj_mieso(int zjedzone_mieso)
{
	this->mieso = this->mieso - zjedzone_mieso;
	if (this->mieso <= 0) {
		zjedzone_mieso = zjedzone_mieso + this->mieso;
		this->mieso = 0;
	}
	return zjedzone_mieso;
}

void Pole::dodaj_mieso(int mieso)
{
	this->mieso = this->mieso + mieso;
}
