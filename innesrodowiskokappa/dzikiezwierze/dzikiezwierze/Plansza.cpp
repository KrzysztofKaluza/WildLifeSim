#include "Plansza.h"

Plansza::Plansza()
{
	srand(time(NULL));
	this->rozmiar_pola = 2;
	this->rozmiar_planszy_x = 0;
	this->rozmiar_planszy_y = 0;
	this->martwi_miesozercy = 0;
	this->martwi_roslinozercy = 0;
}

Plansza::~Plansza()
{
	
	for (int i = 0; i < this->plansza.size();i++) {
		for (int j = 0; j < this->plansza[i].size(); j++) {
			delete this->plansza[i][j];
		}
	}
	for (int i = 0; i < this->zwierzeta.size(); i++) {
		delete this->zwierzeta[i];
	}
}

void Plansza::generuj_plansze(int rozmiar_x, int rozmiar_y) {
	unsigned short wybor = 0;
	
	for (int i=0;i<rozmiar_y;i++) {
		
		this->plansza.push_back(std::vector<Pole*>());

		for (int j=0;j<rozmiar_x;j++) {
			wybor = rand() % 3;
			switch (wybor)
			{

			case 0:
				this->plansza[i].push_back(new Laka());
				break;
			case 1:
				this->plansza[i].push_back(new ZrodloWody());
				break;
			default:
				this->plansza[i].push_back(new KrzewOwocowy());
				break;
			}

			
		}
	}
	this->rozmiar_planszy_x = rozmiar_x * this->rozmiar_pola;
	this->rozmiar_planszy_y = rozmiar_y * this->rozmiar_pola;
}

void Plansza::ekosystem()
{
	
	int ile_zwierzat = rand() % 5 + 1;
	int ile_roslinozercow = round((float)ile_zwierzat * (2.f / 3.f));
	int j = 0;
	for (int i = 0; i < ile_zwierzat; i++) {
		if (j < ile_roslinozercow) {
			int pos_x = rand() % this->rozmiar_planszy_x;
			int pos_y = rand() % this->rozmiar_planszy_y;
			int index_x = floor(pos_x / this->rozmiar_pola);
			int index_y = floor(pos_y / this->rozmiar_pola);
			this->zwierzeta.push_back(new Roslinozerca(this->roslinozerca, pos_x, pos_y, this->plansza[index_x][index_y]->getRodzaj_pola()));
			j++;
		}
		else {
			int pos_x = rand() % this->rozmiar_planszy_x;
			int pos_y = rand() % this->rozmiar_planszy_y;
			int index_x = floor(pos_x / this->rozmiar_pola);
			int index_y = floor(pos_y / this->rozmiar_pola);
			this->zwierzeta.push_back(new Miesozerca(this->miesozerca, pos_x, pos_y, this->plansza[index_x][index_y]->getRodzaj_pola()));
			j++;
		}
	}

}

void Plansza::update()
{
	
	int index_x = 0;
	int index_y = 0;
	for (int i = 0; i < this->zwierzeta.size(); i++) {
		index_x = floor(this->zwierzeta[i]->getPozycja_x() / this->rozmiar_pola);
		index_y = floor(this->zwierzeta[i]->getPozycja_y() / this->rozmiar_pola);
		this->zwierzeta[i]->wczytaj_pole(this->plansza[index_x][index_y]->getRodzaj_pola());
		this->zwierzeta[i]->update();

		//this->plansza[index_x][index_y]->uzyj_zasob(zwierzeta[i]);

		switch (this->zwierzeta[i]->getStan()) {
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
}

void Plansza::zlicz_martwe_zwierzeta()
{
	for (int i = 0;i < this->zwierzeta.size();i++) {
		if (!this->zwierzeta[i]->getCzy_zyje()) {
			if (this->zwierzeta[i]->getNazwa_stworzenia() == this->roslinozerca) {
				this->martwi_roslinozercy++;
			}
			else if (this->zwierzeta[i]->getNazwa_stworzenia() == this->miesozerca) {
				this->martwi_miesozercy++;
			}
		}
	}
}

int Plansza::getMartwi_roslinozercy()
{
	return this->martwi_roslinozercy;
}

int Plansza::getMartwi_miesozercy()
{
	return this->martwi_miesozercy;
}
