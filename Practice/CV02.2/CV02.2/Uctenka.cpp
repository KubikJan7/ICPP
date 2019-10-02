#include "Uctenka.h"
#include <iostream>
#include <string>

using namespace std;

void Uctenka::precistUctenku() {
	cout << "id uctenky: "<< cisloUctenky<< " castka: " << castka << " dph: " << dph << endl;
}
int Uctenka::getCisloUctenky() const {
	return this->cisloUctenky;
}
void Uctenka::setCisloUctenky(int cisloUctenky) {
	this->cisloUctenky = cisloUctenky;
}
double Uctenka::getCastka()const {
	return castka;
}
double Uctenka::getDph()const {
	return dph;
}
void Uctenka::setDph(double dph) {
	this->dph = dph;
}
void Uctenka::setCastka(int castka) {
	this->castka = castka;
}
