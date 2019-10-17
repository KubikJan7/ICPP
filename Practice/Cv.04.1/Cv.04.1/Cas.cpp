#include "Cas.h"
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

Cas::Cas()
{
	_hodiny = 0;
	_minuty = 0;
	_sekundy = 0;
}

Cas::Cas(int _hodiny, int _minuty, int _sekundy) {
	this->_hodiny = _hodiny;
	this->_minuty = _minuty;
	this->_sekundy = _sekundy;
}

int Cas::compareTo(IComparable* obj) const
{
	if (this->toString() == obj->toString())
		if (_hodiny == dynamic_cast<Cas*>(obj)->_hodiny) {
			if (_minuty == dynamic_cast<Cas*>(obj)->_minuty) {
				if (_sekundy == dynamic_cast<Cas*>(obj)->_sekundy) {
					return 0;
				}
				else if (_sekundy < dynamic_cast<Cas*>(obj)->_sekundy) {
					return -1;
				}
				else {
					return 1;
				}
			}
			else if (_minuty < dynamic_cast<Cas*>(obj)->_minuty) {
				return -1;
			}
			else {
				return 1;
			}
		}
		else if (_hodiny < dynamic_cast<Cas*>(obj)->_hodiny) {
			return -1;
		}
		else {
			return 1;
		}
	else {
		try {
			throw string("Porovnavaji se rozdilne formaty.");
		}
		catch (string msg) {
			cout << msg << endl;
		}
	}
}

std::string Cas::toString() const
{
	return typeid(this).name();
}