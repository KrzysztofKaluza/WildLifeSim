#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <fstream>
using namespace std;

class Interface
{
private:
	short wybor_w_menu;
protected:

public:
	Interface();
	unsigned short menu();
	void zapisz_do_csv(int ile_martwych_mieso, int ile_martwych_rosli,
		int ile_mieso, int ile_rosli);
	void pozegnanie();
	void nie_ma_opcji();
};

#endif