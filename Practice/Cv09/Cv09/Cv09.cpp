// Cv09.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <sstream>
using namespace std;
struct Datum {
	int den, mesic, rok;
};

struct Adresa {
	string ulice;
	string mesto;
	int psc;
};

struct Osoba {
	string jmeno;
	string prijmeni;
	Datum narozeniny;
	Adresa bydliste;
};

void ulozString(string str, ofstream& f) {
	int velikost = str.size();
	f.write((char*)&velikost, sizeof(int));

	//const char * znaky = str.c_str();
	//const char * znaky = str.data();
	const char * znaky = &str[0];
	f.write(znaky,velikost);

}
void uloz(Osoba& osoba, ofstream& f) {
	//f.write((char*)&osoba, sizeof(Osoba));

	// int velikost - char char char char char
	//char char char char char char char char char char char char cahr char
	// M E S T O /0 /0 /0 /0 /0 /0 /0 /0 /0 /0 /0

	//char char char char char char char char /0
}

int main()
{
	Osoba[] os = {
		{"Petr", "Maly",{10,5,2000}, {"Janackova","As", 20050}};
	{"Petr","Velky",{10, 5, 2000},{"Janackova", "As", 20050}}
	};
	ofstream f{ "osoby.dat", ios_base::out | ios_base::binary };
	for
}
