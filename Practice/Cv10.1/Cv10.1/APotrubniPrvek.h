#ifndef A_POTRUBNI_PRVEK_H
#define A_POTRUBNI_PRVEK_H
#include "IPotrubi.h"

struct APotrubniPrvek {
	virtual ~APotrubniPrvek() {}
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const = 0;
	int _x;
	int _y;
};
#endif
