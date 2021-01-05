#include "Miesozerca.h"

Miesozerca::Miesozerca(int id_zwierza, string nazwa, int pozycja_x, int pozycja_y, Pole* pole,
	int maxObszarX, int maxObszarY)
{
	this->id_zwierzecia = id_zwierza;
	this->setNazwa_stworzenia(nazwa);
	this->pozycja.x = pozycja_x;
	this->pozycja.y = pozycja_y;
	this->pole_na_ktorym_stoi = pole;
	this->maxObszarX = maxObszarX;
	this->maxObszarY = maxObszarY;
	this->prog_ataku_miesozercow = 30;
}

void Miesozerca::update()
{
	
	//zmiana statystyk glodu i pragnienia
	this->glodnienie();
	this->dehydracja();
	if (this->czy_zyje) {
		//uruchomienie maszyny stanow
		this->maszyna_stanow();
		//wykonywanie czynnosci aktualnego stanu
		this->czesc_operacyjna();
	}
}



void Miesozerca::maszyna_stanow()
{
	if (this->stan = State::koniec) {
		this->stan = State::koniec;
	}
	else if (this->glod <= 0 || this->pragnienie <= 0 || this->stan == State::smierc) {
		this->stan = State::smierc;
		this->pole_na_ktorym_stoi->smierc_zwierzatka(this->przenoszone_mieso);
		this->czy_zyje = false;
		this->stan = State::koniec;
	}
	else {
		if (this->getGlod() < this->getProg_szukania_pozywienia()) {
			this->szuka_jedzenie = true;
		}
		else {
			this->szuka_jedzenie = false;
		}
		if (this->getPragnienie() < this->getProg_szukania_wody()) {
			this->szuka_picie = true;
		}
		else {
			this->szuka_picie = false;
		}

		if (!this->szuka_jedzenie && !this->szuka_picie) {
			this->stan = State::odpoczynek;
		}
		else if (!this->szuka_jedzenie && this->szuka_picie) {
			this->stan = State::przemieszczanie;
			if (this->pole_na_ktorym_stoi->getRodzaj_pola() == Typ_pola::ZRODLO_WODY) {
				if (this->pole_na_ktorym_stoi->get_zasob() > 0) {
					this->stan = State::picie;
				}
			}
		}
		else if (this->szuka_jedzenie && !this->szuka_picie) {
			this->stan = State::przemieszczanie;
			if (this->pole_na_ktorym_stoi->get_mieso() >= 0) {
				this->stan = State::jedzenie;
			}
		}
		else {
			this->stan = State::przemieszczanie;
			if (this->pole_na_ktorym_stoi->getRodzaj_pola() == Typ_pola::ZRODLO_WODY) {
				if (this->pole_na_ktorym_stoi->get_zasob() > 0) {
					this->stan = State::picie;
				}
			}
			if (this->pole_na_ktorym_stoi->get_mieso() >= 0) {
				this->stan = State::jedzenie;
			}
		}
	}
}

void Miesozerca::czesc_operacyjna()
{
	float wsp_x;
	float wsp_y;
	double kat;
	double kierunek;
	double dystans;
	int ile_brakuje = NULL;
	switch (this->stan) {
	case State::przemieszczanie:
		if (this->glod >= this->prog_ataku_miesozercow) {
			wsp_x = static_cast<float>(this->najblizsza_ofiara_roslinozerca->getPozycja_x()) - static_cast<float>(this->pozycja.x);
			wsp_y = static_cast<float>(this->najblizsza_ofiara_roslinozerca->getPozycja_y()) - static_cast<float>(this->pozycja.y);
			kat = atan(wsp_y / wsp_x);
			kierunek = kat / 360.f;
			dystans = sqrt(pow(wsp_x, 2) + pow(wsp_y, 2));
			if (dystans < 3) {
				this->pozycja.x = this->najblizsza_ofiara_roslinozerca->getPozycja_x();
				this->pozycja.y = this->najblizsza_ofiara_roslinozerca->getPozycja_y();
				this->najblizsza_ofiara_roslinozerca->usmierc();
			}
			else { 
				this->ruch(kierunek); 
			}
		}
		else {
			wsp_x = static_cast<float>(this->najblizsza_ofiara_zwierze->getPozycja_x()) - static_cast<float>(this->pozycja.x);
			wsp_y = static_cast<float>(this->najblizsza_ofiara_zwierze->getPozycja_y()) - static_cast<float>(this->pozycja.y);
			kat = atan(wsp_y / wsp_x);
			kierunek = kat / 360.f;
			dystans = sqrt(pow(wsp_x, 2) + pow(wsp_y, 2));
			if (dystans < 3) {
				this->pozycja.x = this->najblizsza_ofiara_zwierze->getPozycja_x();
				this->pozycja.y = this->najblizsza_ofiara_zwierze->getPozycja_y();
				this->najblizsza_ofiara_zwierze->usmierc();
			}
			else {
				this->ruch(kierunek);
			}
		}
		break;
	case State::jedzenie:
		ile_brakuje = MAX_GLOD - this->glod;
		this->glod = this->glod + this->pole_na_ktorym_stoi->jedz_mieso(ile_brakuje);
		break;
	case State::picie:
		ile_brakuje = MAX_PRAGNIENIE - this->pragnienie;
		this->pragnienie = this->pragnienie + this->pole_na_ktorym_stoi->uzyj_zasob(ile_brakuje);
		break;
	default:
		break;
	}
}

void Miesozerca::setNajblizsza_ofiara_zwierze(Stworzenie * zwierz)
{
	this->najblizsza_ofiara_zwierze = zwierz;
}

void Miesozerca::setNajblizsza_ofiara_roslinozerca(Stworzenie * roslinozerca)
{
	this->najblizsza_ofiara_roslinozerca = roslinozerca;
}

void Miesozerca::ruch(float kierunek)
{
	if (0.125 > this->kierunek >= 0 || this->kierunek == 1) {
		if (!this->czyPozaObszarem(this->pozycja.x + 1, this->pozycja.y)) {
			this->pozycja.x = this->pozycja.x + 2;
		}
		else {
			this->kierunek = 1.f - kierunek;
		}
	}
	else if (0.25 > this->kierunek >= 0.125) {
		if (!this->czyPozaObszarem(this->pozycja.x + 1, this->pozycja.y + 1)) {
			this->pozycja.x = this->pozycja.x + 1;
			this->pozycja.y = this->pozycja.y + 1;
		}
		else {
			this->kierunek = 1.f - kierunek;
		}
	}
	else if (0.375 > this->kierunek >= 0.25) {
		if (!this->czyPozaObszarem(this->pozycja.x, this->pozycja.y + 1)) {
			this->pozycja.y = this->pozycja.y + 2;
		}
		else {
			this->kierunek = 1.f - kierunek;
		}
	}
	else if (0.5 > this->kierunek >= 0.375) {
		if (!this->czyPozaObszarem(this->pozycja.x - 1, this->pozycja.y + 1)) {
			this->pozycja.x = this->pozycja.x - 1;
			this->pozycja.y = this->pozycja.y + 1;
		}
		else {
			this->kierunek = 1.f - kierunek;
		}
	}
	else if (0.625 > this->kierunek >= 0.5) {
		if (!this->czyPozaObszarem(this->pozycja.x - 1, this->pozycja.y)) {
			this->pozycja.x = this->pozycja.x - 2;
		}
		else {
			this->kierunek = 1.f - kierunek;
		}
	}
	else if (0.75 > this->kierunek >= 0.625) {
		if (!this->czyPozaObszarem(this->pozycja.x - 1, this->pozycja.y - 1)) {
			this->pozycja.x = this->pozycja.x - 1;
			this->pozycja.y = this->pozycja.y - 1;
		}
		else {
			this->kierunek = 1.f - kierunek;
		}
	}
	else if (0.875 > this->kierunek >= 0.75) {
		if (!this->czyPozaObszarem(this->pozycja.x, this->pozycja.y - 1)) {
			this->pozycja.y = this->pozycja.y - 2;
		}
		else {
			this->kierunek = 1.f - kierunek;
		}
	}
	else if (1 > this->kierunek >= 0.875) {
		if (!this->czyPozaObszarem(this->pozycja.x + 1, this->pozycja.y - 1)) {
			this->pozycja.x = this->pozycja.x + 1;
			this->pozycja.y = this->pozycja.y - 1;
		}
		else {
			this->kierunek = 1.f - kierunek;
		}
	}
}

void Miesozerca::glodnienie()
{
	this->glod = this->glod - 3;
}

void Miesozerca::dehydracja()
{
	this->pragnienie = this->pragnienie - 3;
}


