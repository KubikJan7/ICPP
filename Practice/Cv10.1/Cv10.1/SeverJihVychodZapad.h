#ifndef SEVER_JIH_VYCHOD_ZAPAD_H
#define SEVER_JIH_VYCHOD_ZAPAD_H

#include "APotrubniPrvek.h"
struct SeverJihVychodZapad :APotrubniPrvek{
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi);
};

#endif