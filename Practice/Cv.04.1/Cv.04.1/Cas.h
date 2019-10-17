#ifndef Cas_H
#define Cas_H

#include"IComparable.h"
struct Cas:IComparable {
public:
	int _hodiny;
	int _minuty;
	int _sekundy;
public:
	Cas();
	Cas(int _hodiny, int _minuty, int _sekundy); 
	virtual int compareTo(IComparable* obj) const;
	std::string toString() const;
};

#endif