#ifndef NIC_H
#define NIC_H

#include "APotrubniPrvek.h"
struct Nic : APotrubniPrvek {
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi);
};

#endif