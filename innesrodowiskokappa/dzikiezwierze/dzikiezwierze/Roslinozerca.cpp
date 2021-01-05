#include "Roslinozerca.h"



Roslinozerca::Roslinozerca(string nazwa, int pozycja_x, int pozycja_y, string rodzaj_pola)
{
	this->setNazwa_stworzenia(nazwa);
	this->pozycja.x = pozycja_x;
	this->pozycja.y = pozycja_y;
}


void Roslinozerca::glodnienie()
{
	this->glod = this->glod - 3;
}

void Roslinozerca::dehydracja()
{
	this->pragnienie = this->pragnienie - 3;
}

void Roslinozerca::update()
{
	
	//zmiana statystyk glodu i pragnienia
	this->glodnienie();
	this->dehydracja();
	if (this->glod <= 0 || this->pragnienie <= 0) {
		this->czy_zyje = false;
	}
	if (this->czy_zyje) {
		//uruchomienie maszyny stanow
		this->maszyna_stanow();
		//wykonywanie czynnosci aktualnego stanu
		this->czesc_operacyjna();
	}
	

}

void Roslinozerca::maszyna_stanow()
{
	/*if (this->getGlod() >= this->getProg_szukania_pozywienia && this->getPragnienie >= this->getProg_szukania_wody) {
		this->stan = State::odpoczynek;
	}
	else {
		this->stan = State::przemieszczanie;
		if (true) {
			//jeœli szuka pokarmu i go znajdzie
			this->stan = State::jedzenie;
		}
		else if (true) {
			//jeœli szuka picia i go znajdzie
			this->stan = State::picie;
		}
	}*/
}

void Roslinozerca::czesc_operacyjna()
{
	switch (this->stan) {
	case State::odpoczynek:
		break;
	case State::przemieszczanie:
		break;
	case State::jedzenie:
		break;
	case State::picie:
		break;
	default:
		break;
	}
}


