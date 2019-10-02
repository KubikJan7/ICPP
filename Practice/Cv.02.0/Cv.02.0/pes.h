#ifndef _PES_H
#define _PES_H
#include <string>

using namespace std;


struct Pes {
private:
	string jmeno;
	int vek;
	string pocetPacek;
	int delkaOcasu;
	

public:
	Pes(string jmeno);
	void stekej();
	void vypisPocetPsu();
};

#endif