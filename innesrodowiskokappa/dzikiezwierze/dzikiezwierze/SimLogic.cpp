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
			this->~SimLogic();
			break;
		case 2:
			this->ProgramUruchomiony = false;
			break;
		default:
			
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
	long long duration = NULL;
	while (duration < this->simulation_duration) {
		
		this->plansza.update();

		auto end_t_measure = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<chrono::seconds>(end_t_measure - begin).count();
	}
	this->plansza.zlicz_martwe_zwierzeta();
	//wyciaganie informacji na temat martwych stworzen
	this->plansza.getMartwi_miesozercy();
	this->plansza.getMartwi_roslinozercy();
}

