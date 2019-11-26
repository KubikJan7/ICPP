#ifndef JIH_VYCHOD_ZAPAD_H
#define JIH_VYCHOD_ZAPAD_H

#include "APotrubniPrvek.h"

struct JihVychodZapad : APotrubniPrvek {
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi);
};

#endif