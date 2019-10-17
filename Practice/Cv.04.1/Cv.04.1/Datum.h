#ifndef Datum_H
#define Datum_H

#include"IComparable.h"

struct Datum:IComparable {
private:
	int _den;
	int _mesic;
	int _rok;
public:
	int compareTo(IComparable* obj) const;
	std::string toString() const;
};

#endif