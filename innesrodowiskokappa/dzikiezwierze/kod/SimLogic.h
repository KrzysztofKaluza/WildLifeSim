#ifndef SIMLOGIC_H
#define SIMLOGIC_H

#include "Interface.h"
#include "Plansza.h"

#include <chrono>
#include <thread>

class SimLogic
{
private:
	bool ProgramUruchomiony;
	Interface obsluga_io;
	Plansza plansza;
	int simulation_duration;
	// manager stanow
public:
	SimLogic();
	~SimLogic();
	void start_program();
	void start_simulation();
	void simulate();
	void przygotowanie_informacji_i_zapis();
};

#endif