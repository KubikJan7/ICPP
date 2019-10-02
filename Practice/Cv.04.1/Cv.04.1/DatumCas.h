#include"Datum.h"
#include"Cas.h"
#include"IComparable.h"

struct DatumCas:IComparable {
	Datum _datum;
	Cas _cas;
};