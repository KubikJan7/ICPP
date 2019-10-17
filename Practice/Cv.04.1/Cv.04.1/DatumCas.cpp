#include "DatumCas.h"
#include <string>

using namespace std;

int DatumCas::compareTo(IComparable* obj) const
{
	return 0;
}

std::string DatumCas::toString() const
{
	return _datum.toString() + _cas.toString();
}
