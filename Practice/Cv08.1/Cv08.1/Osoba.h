#ifndef _OSOBA_H
#define _OSOBA_H
#include<string>
#include"Adresa.h"
#include"Datum.h"

struct Osoba {
	std::string _jmeno;
	std::string _prijmeni;
	Adresa _trvaleBydliste;
	Datum _datumNarozeni;

	Osoba(std::string jmeno, std::string prijmeni, Adresa trvaleBydliste, Datum datumNarozeni);
	Osoba();
};
#endif