#include"Osoba.h"
#include"Datum.h"
#include"Adresa.h"
#include<string>

using namespace std;
Osoba::Osoba(string jmeno, string prijmeni, Adresa trvaleBydliste, Datum datumNarozeni) {
	_jmeno = jmeno;
	_prijmeni = prijmeni;
	_trvaleBydliste = trvaleBydliste;
	_datumNarozeni = datumNarozeni;
}

Osoba::Osoba() : _jmeno(""), _prijmeni(""), _trvaleBydliste(), _datumNarozeni() {

}