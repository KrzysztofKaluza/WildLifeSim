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

void Interface::zapisz_do_csv(int ile_martwych_mieso, int ile_martwych_rosli, int ile_mieso, int ile_rosli)
{
	fstream file;
	file.open("wynik.csv", ios::out);
	file << "gatunek,zywi,martwi\n";
	file << "miesozercy," << ile_mieso << "," << ile_martwych_mieso << "\n";
	file << "roslinozercy," << ile_rosli << "," << ile_martwych_rosli << "\n";
	file.close();
}

void Interface::pozegnanie()
{
	cout << "\nZAKONCZENIE PROGRAMU\n";
}

void Interface::nie_ma_opcji()
{
	cout << "\nBRAK OPCJI\n";
}





