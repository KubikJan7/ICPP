#pragma once
//#ifndef _POKLADNA_H
//#define _POKLADNA_H
#include <string>
#include "Uctenka.h"

struct Pokladna {
private:
	Uctenka* poleUctenek;
	int pocetVydanychUctenek;
	static int citacId;
public:
	Pokladna();
	~Pokladna();
	Uctenka& vystavUctenku(double castka, double dph);
	Uctenka& dejUctenku(int cisloUctenky);
	double dejCastku() const;
	double dejCastkuVcDph() const;
};
//#endif
