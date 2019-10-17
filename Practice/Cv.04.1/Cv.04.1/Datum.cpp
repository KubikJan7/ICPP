#include "Datum.h"
#include <string>

using namespace std;

int Datum::compareTo(IComparable* obj) const
{
	return 0;
}

std::string Datum::toString() const
{
	return "rok: " + to_string(_rok) + "mes: " + to_string(_mesic) + "den: " + to_string(_den);
}
