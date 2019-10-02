#include<iostream>
#include "Pokladna.h"

int Pokladna::citacId = 1000; // statický atribut

Pokladna::Pokladna() {
	pocetVydanychUctenek = 0;
	poleUctenek = new Uctenka[10];
}
Pokladna::~Pokladna() {
	delete[] poleUctenek;
}

Uctenka& Pokladna::vystavUctenku(double castka, double dph) {
	int index = pocetVydanychUctenek;
	poleUctenek[index].setCastka(castka);
	poleUctenek[index].setDph(dph);
	poleUctenek[index].setCisloUctenky(citacId++);
	pocetVydanychUctenek++;
	return poleUctenek[index];
}
Uctenka& Pokladna::dejUctenku(int cisloUctenky) {
	for (int i = 0; i < pocetVydanychUctenek; i++) {
		if (poleUctenek[i].getCisloUctenky() == cisloUctenky)
			return poleUctenek[i];	
	}
	return poleUctenek[0];
}
double Pokladna::dejCastku() const {
	double suma = 0;
	for (int i = 0; i < pocetVydanychUctenek; i++)
		suma += poleUctenek[i].getCastka();
	return suma;
}
double Pokladna::dejCastkuVcDph() const {
	double suma = 0;
	for (int i = 0; i < pocetVydanychUctenek; i++)
		suma += poleUctenek[i].getCastka() * (1 + poleUctenek[i].getDph());
	return suma;
}