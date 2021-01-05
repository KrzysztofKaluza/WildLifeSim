#include "Stworzenie.h"

Stworzenie::Stworzenie()
{
	this->czy_zyje = true;
	this->HP = rand() % 50 + 101;
	this->glod = MAX_GLOD;
	this->pragnienie = MAX_PRAGNIENIE;
	this->szybkosc = rand() % 100 + 101;
	this->obrazenia = rand() % 30 + 31;
	this->przenoszone_mieso = rand() % 30 + 21;
	this->szuka_jedzenie = false;
	this->szuka_picie = false;
	this->czy_dotarl = true;
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

void Stworzenie::wczytaj_pole(Pole* pole)
{
	this->pole_na_ktorym_stoi = pole;
}

bool Stworzenie::czyPozaObszarem(int pos_x, int pos_y)
{
	if (pos_x < 0|| pos_y < 0
		|| pos_x >= this->maxObszarX 
		|| pos_y >= this->maxObszarY) {
		return true;
	}
	return false;
}

void Stworzenie::setNajblizsza_ofiara_zwierze(Stworzenie * zwierz)
{
}

void Stworzenie::setNajblizsza_ofiara_roslinozerca(Stworzenie * roslinozerca)
{
}

void Stworzenie::usmierc()
{
	this->stan = State::smierc;
}

