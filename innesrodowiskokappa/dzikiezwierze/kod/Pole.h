#ifndef POLE_H
#define POLE_H

#include <string>
using namespace std;
enum Typ_pola{LAKA=0, ZRODLO_WODY, KRZEW_OWOCOWY};
class Pole
{
protected:
	Typ_pola rodzaj_pola;
	int mieso;
public:
	Pole();
	virtual void ustaw_zasob() = 0;
	virtual int uzyj_zasob(int zasob) = 0;
	virtual int get_zasob() = 0;
	virtual Typ_pola getRodzaj_pola();
	int get_mieso();
	int uzyj_mieso(int zjedzone_mieso);
	void dodaj_mieso(int mieso);

};

#endif
