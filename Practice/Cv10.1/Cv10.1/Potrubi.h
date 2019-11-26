#ifndef POTRUBI_H
#define POTRUBI_H

#include "IPotrubi.h"
#include <iostream>
#include <sstream>

struct Potrubi : IPotrubi{
private:
	APotrubniPrvek** prvky;
	int rozmer;

public:
	Potrubi(std::istringstream &iss);
	~Potrubi();
	virtual APotrubniPrvek* DejPrvek(int x, int y)const override;
	virtual bool JePotrubiOk()const override;
};

#endif
