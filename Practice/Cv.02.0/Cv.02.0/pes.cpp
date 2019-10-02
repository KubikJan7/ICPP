#include "stdafx.h"
#include <iostream>
#include "pes.h"
using namespace std;
int pocetPsu = 0;
void Pes::vypisPocetPsu() {
	cout << "Psu: " << pocetPsu << endl;
}
Pes::Pes(string jmeno) {
	this->jmeno = jmeno;
	vek = 0;
	pocetPacek = 4;
	delkaOcasu = 10;
	cout << jmeno << " prisel" << endl;

	pocetPsu++;
}
/*Pes::Pes() {   - Destruktor, spíše se nepoužívá

}*/
void Pes::stekej() {
	cout << "HAF HAF " << endl;
}