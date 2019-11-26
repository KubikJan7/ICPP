#ifndef SEVER_JIH_H
#define SEVER_JIH_H

#include "APotrubniPrvek.h"
struct SeverJih : APotrubniPrvek {
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi);
};

#endif