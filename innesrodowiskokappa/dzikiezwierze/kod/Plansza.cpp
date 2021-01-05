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
	/*
		funkcja wpisuje do wektora 2D obiekty pól trzech typów: łąba, źródło wody, krzew owocowy
	*/
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
	// plansza jako obiekt przechowuje swój rozmiar w tych zmiennych
	this->rozmiar_planszy_x = rozmiar_x * this->rozmiar_pola;
	this->rozmiar_planszy_y = rozmiar_y * this->rozmiar_pola;
}

void Plansza::ekosystem()
{
	/*
		funkcja wypełnia wektor zwierzeta przy pomocy obiektów klas Roslinozerca i Miesozerca, przydziela liczbę obiektów
	*/
	int ile_zwierzat = ILE_ZWIERZAT;
	int ile_roslinozercow = round(ile_zwierzat * (2.f / 3.f));
	this->ilosc_roslinozercow = ile_roslinozercow;
	int j = 0;
	for (int i = 0; i < ile_zwierzat; i++) {
		if (j < ile_roslinozercow) {
			int pos_x = rand() % this->rozmiar_planszy_x;
			int pos_y = rand() % this->rozmiar_planszy_y;
			int index_x = floor(pos_x / this->rozmiar_pola);
			int index_y = floor(pos_y / this->rozmiar_pola);
			this->zwierzeta.push_back(new Roslinozerca(i, this->roslinozerca, pos_x, pos_y, this->plansza[index_x][index_y], rozmiar_planszy_x, rozmiar_planszy_y));
			j++;
		}
		else {
			int pos_x = rand() % this->rozmiar_planszy_x;
			int pos_y = rand() % this->rozmiar_planszy_y;
			int index_x = floor(pos_x / this->rozmiar_pola);
			int index_y = floor(pos_y / this->rozmiar_pola);
			this->zwierzeta.push_back(new Miesozerca(i, this->miesozerca, pos_x, pos_y, this->plansza[index_x][index_y], rozmiar_planszy_x, rozmiar_planszy_y));
			j++;
		}
	}

}

void Plansza::update()
{
	//następuje tutaj wykonanie ruchu każdego ze zwierząt w turze
	znajdz_najblizsze_siebie_zwierzeta();
	int index_x = 0;
	int index_y = 0;
	for (int i = 0; i < this->zwierzeta.size(); i++) {
		index_x = floor(this->zwierzeta[i]->getPozycja_x() / this->rozmiar_pola);
		index_y = floor(this->zwierzeta[i]->getPozycja_y() / this->rozmiar_pola);
		this->zwierzeta[i]->wczytaj_pole(this->plansza[index_x][index_y]);
		if (this->zwierzeta[i]->getNazwa_stworzenia() == this->miesozerca) {
			this->zwierzeta[i]->setNajblizsza_ofiara_roslinozerca(this->tablica_najblizszych_roslinozercow[i]);
			this->zwierzeta[i]->setNajblizsza_ofiara_zwierze(this->tablica_najblizszych_zwierzat[i]);
		}
		
		this->zwierzeta[i]->update();
		
	}

}

void Plansza::zlicz_martwe_zwierzeta()
{
	//funkcja do liczenia zwierząt martwych
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

int Plansza::getIlosc_roslinozercow()
{
	return this->ilosc_roslinozercow;
}

void Plansza::znajdz_najblizsze_siebie_zwierzeta()
{
	/*funkcja, która pozwala sprawdzić dla każdego mięsożercy swoje najbliższe potencjalne ofiary*/
	int y = 0;
	int x = 0;
	int c_zwierze = 0;
	int c_roslinozerca = 0;
	int c_n = 0;
	int j_dla_najblizszego_zwierza = 0;
	int j_dla_najblizszego_roslinozercy = 0;
	for (int i = 0; i < this->zwierzeta.size(); i++) {
		if (this->zwierzeta[i]->getNazwa_stworzenia() == this->miesozerca) {
			for (int j = 0; j < this->zwierzeta.size(); j++) {
				if (j == i) {
					break;
				}
				y = abs(this->zwierzeta[i]->getPozycja_y() - this->zwierzeta[j]->getPozycja_y());
				x = abs(this->zwierzeta[i]->getPozycja_x() - this->zwierzeta[j]->getPozycja_x());
				c_n = floor(sqrt(pow(x, 2) + pow(y, 2)));
				if (i == 0 && j == 1) {
					c_zwierze = c_n;
					c_roslinozerca = c_n;
				}
				if (i != 0 && j == 0) {
					c_zwierze = c_n;
					c_roslinozerca = c_n;
				}
				if (c_n < c_zwierze) {
					c_zwierze = c_n;
					j_dla_najblizszego_zwierza = j;
				}
				if (this->zwierzeta[j]->getNazwa_stworzenia() == this->roslinozerca) {
					if (c_n < c_roslinozerca) {
						c_roslinozerca = c_n;
						j_dla_najblizszego_roslinozercy = j;
					}
				}

			}
			this->tablica_najblizszych_zwierzat[i] = this->zwierzeta[j_dla_najblizszego_zwierza];
			this->tablica_najblizszych_roslinozercow[i] = this->zwierzeta[j_dla_najblizszego_roslinozercy];
		}
		
	}
}
