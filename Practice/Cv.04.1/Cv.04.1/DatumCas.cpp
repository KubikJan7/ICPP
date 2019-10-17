#include "DatumCas.h"
#include <string>

using namespace std;

DatumCas::DatumCas(Datum* _datum, Cas* _cas)
{
	this->_datum = _datum;
	this->_cas = _cas;
}

int DatumCas::compareTo(IComparable* obj) const
{
	if (this->toString() == obj->toString()) {
		int _dateResult = _datum->compareTo(dynamic_cast<DatumCas*>(obj)->_datum);
		int _timeResult = _cas->compareTo(dynamic_cast<DatumCas*>(obj)->_cas);
		if (_dateResult == 0) {
			if (_timeResult == 0) {
				return 0;
			}
			else if (_timeResult == -1) {
				return -1;
			}
			else {
				return 1;
			}
		}
		else if (_dateResult == -1) {
			return -1;
		}
		else {
			return 1;
		}
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

std::string DatumCas::toString() const
{
	return typeid(this).name();
}
