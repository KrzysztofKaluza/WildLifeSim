#include "SimLogic.h"

SimLogic::SimLogic() {
	this->ProgramUruchomiony = true;
	this->simulation_duration = 10;
}

SimLogic::~SimLogic()
{
	this->plansza.~Plansza();
}

void SimLogic::start_program() {

	while (this->ProgramUruchomiony) {
		
		switch (obsluga_io.menu())
		{
		case 1:
			this->start_simulation();
			this->simulate();
			this->przygotowanie_informacji_i_zapis();
			this->~SimLogic();
			break;
		case 2:
			this->obsluga_io.pozegnanie();
			this->ProgramUruchomiony = false;
			break;
		default:
			this->obsluga_io.nie_ma_opcji();
			break;
		}
	}
}

void SimLogic::start_simulation() {

	this->plansza.generuj_plansze(10, 10);
	this->plansza.ekosystem();

}

void SimLogic::simulate()
{
	auto begin = std::chrono::high_resolution_clock::now();
	int duration = NULL;
	int duration_one_loop = NULL;
	while (duration < this->simulation_duration) {
		auto begin_one_loop = std::chrono::high_resolution_clock::now();
		this->plansza.update();

		auto end_t_measure = std::chrono::high_resolution_clock::now();
		duration_one_loop = std::chrono::duration_cast<chrono::milliseconds>(end_t_measure - begin_one_loop).count();
		std::chrono::milliseconds sleep_time(1000 - duration_one_loop);
		std::this_thread::sleep_for(sleep_time);
		duration = std::chrono::duration_cast<chrono::seconds>(end_t_measure - begin).count();
		
	}
}

void SimLogic::przygotowanie_informacji_i_zapis()
{
	this->plansza.zlicz_martwe_zwierzeta();
	int ile_miesozercow_martwych = this->plansza.getMartwi_miesozercy();
	int ile_roslinozercow_martwych = this->plansza.getMartwi_roslinozercy();
	int ile_roslinozercow = this->plansza.getIlosc_roslinozercow();
	int ile_miesozercow = ILE_ZWIERZAT - ile_roslinozercow;
	this->obsluga_io.zapisz_do_csv(ile_miesozercow_martwych, ile_roslinozercow_martwych, ile_miesozercow, ile_roslinozercow);
}

