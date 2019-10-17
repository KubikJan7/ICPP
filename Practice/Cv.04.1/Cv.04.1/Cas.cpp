#include "Cas.h"
#include <string>
#include <iostream>
using namespace std;

Cas::Cas(int _hodiny, int _minuty, int _sekundy) {
	this->_hodiny = _hodiny;
	this->_minuty = _minuty;
	this->_sekundy = _sekundy;
}

int Cas::compareTo(IComparable* obj) const
{
	if (this == obj) {
		cout << "Rovnaji se" << endl;
		return 0;
	}
	else if (this < obj) {
		cout << "Prvni je mensi" << endl;
		return -1;
	}
	else {
		cout << "Prvni je vetsi" << endl;
		return 1;
	}
}

std::string Cas::toString() const
{
	return "hod: " + to_string(_hodiny) + "min: " + to_string(_minuty) + "sek: " + to_string(_sekundy);
}