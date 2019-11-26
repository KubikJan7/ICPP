#ifndef VYCHOD_ZAPAD_H
#define VYCHOD_ZAPAD_H

#include "APotrubniPrvek.h"

struct VychodZapad : APotrubniPrvek{
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi);
};

#endif

