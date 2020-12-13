#include "Stworzenie.h"

Stworzenie::Stworzenie()
{
	this->czy_zyje = true;
	this->HP = rand() % 50 + 101;
	this->glod = 100;
	this->pragnienie = 100;
	this->szybkosc = rand() % 100 + 101;
	this->obrazenia = rand() % 30 + 31;
}


void Stworzenie::update()
{
}

void Stworzenie::maszyna_stanow()
{
}

State Stworzenie::getStan()
{
	return stan;
}

void Stworzenie::setNazwa_stworzenia(string nazwa) {
	this->nazwa_stworzenia = nazwa;
}

string Stworzenie::getNazwa_stworzenia()
{
	return this->nazwa_stworzenia;
}

int Stworzenie::getHP()
{
	return this->HP;
}

int Stworzenie::getGlod()
{
	return this->glod;
}

int Stworzenie::getPragnienie()
{
	return this->pragnienie;
}

int Stworzenie::getSzybkosc()
{
	return this->szybkosc;
}

int Stworzenie::getObrazenia()
{
	return this->obrazenia;
}

int Stworzenie::getProg_szukania_pozywienia()
{
	return this->prog_szukania_pozywienia;
}

int Stworzenie::getProg_szukania_wody()
{
	return this->prog_szukania_wody;
}

int Stworzenie::getPozycja_x()
{
	return this->pozycja.x;
}

int Stworzenie::getPozycja_y()
{
	return this->pozycja.y;
}

bool Stworzenie::getCzy_zyje()
{
	return this->czy_zyje;
}

void Stworzenie::wczytaj_pole(string nazwa_pola)
{
	this->na_jakim_polu_stoi = nazwa_pola;
}
