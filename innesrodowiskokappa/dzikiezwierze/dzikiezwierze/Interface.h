#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
using namespace std;

class Interface
{
private:
	short wybor_w_menu;
protected:

public:
	Interface();
	//~Interface();
	
	unsigned short menu();
	//void nowa_symulacja();
	//void wczytaj_dane_symulacji(); //jakie dane maj¹ byæ wczytywane??
	//void zapisz_dane_symulacji();
};

#endif