#include "Interface.h"
Interface::Interface() {
	this->wybor_w_menu = 0;
	
}

unsigned short Interface::menu() {
	cout << "1. Rozpocznij symulacje" << endl;
	cout << "2. Zakoncz program" << endl;
	cin >> wybor_w_menu;
	return wybor_w_menu;
}

