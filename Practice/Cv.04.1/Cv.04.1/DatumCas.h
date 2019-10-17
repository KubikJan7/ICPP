#ifndef DatumCas_H
#define DautmCas_H

#include"Datum.h"
#include"Cas.h"
#include"IComparable.h"

struct DatumCas:IComparable {
private:
	Datum* _datum;
	Cas* _cas;
public:
	DatumCas(Datum* _datum, Cas* _cas);
	int compareTo(IComparable* obj) const;
	std::string toString() const;
};
#endif