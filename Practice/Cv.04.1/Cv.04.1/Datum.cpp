#include "Datum.h"
#include <string>

using namespace std;

Datum::Datum()
{
	_den = 0;
	_mesic = 0;
	_rok = 0;
}

Datum::Datum(int _rok, int _mesic, int _den)
{
	this->_rok = _rok;
	this->_mesic = _mesic;
	this->_den = _den;
}

int Datum::compareTo(IComparable* obj) const
{
	if (this->toString() == obj->toString())
		if (_rok == dynamic_cast<Datum*>(obj)->_rok) {
			if (_mesic == dynamic_cast<Datum*>(obj)->_mesic) {
				if (_den == dynamic_cast<Datum*>(obj)->_den) {
					return 0;
				}
				else if (_den < dynamic_cast<Datum*>(obj)->_den) {
					return -1;
				}
				else {
					return 1;
				}
			}
			else if (_mesic < dynamic_cast<Datum*>(obj)->_mesic) {
				return -1;
			}
			else {
				return 1;
			}
		}
		else if (_rok < dynamic_cast<Datum*>(obj)->_rok) {
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

std::string Datum::toString() const
{
	return typeid(this).name();
}
