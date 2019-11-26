#ifndef PRVKY_POTRUBI_H
#define PRVKY_POTRUBI_H

#include "APotrubniPrvek.h"

struct PrvekMinus : APotrubniPrvek {
	PrvekMinus(int x, int y) { _x = x; _y = y; };
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi)const;
};

struct PrvekI : APotrubniPrvek {
	PrvekI(int x, int y) { _x = x; _y = y; };
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi)const;
};

struct PrvekPlus :APotrubniPrvek {
	PrvekPlus(int x, int y) { _x = x; _y = y; };
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi)const;
};

struct PrvekO : APotrubniPrvek {
	PrvekO(int x, int y) { _x = x; _y = y; };
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi)const;
};

struct PrvekT : APotrubniPrvek {
	PrvekT(int x, int y) { _x = x; _y = y; };
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi)const;
};

#endif
