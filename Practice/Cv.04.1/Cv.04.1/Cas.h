#ifndef Cas_H
#define Cas_H

#include"IComparable.h"
struct Cas:IComparable {
private:
	int _hodiny;
	int _minuty;
	int _sekundy;
public:
	Cas(int _hodiny, int _minuty, int _sekundy); 
	int compareTo(IComparable* obj) const;
	std::string toString() const;
};

#endif