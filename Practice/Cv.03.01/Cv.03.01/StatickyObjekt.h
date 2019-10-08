#pragma once
#include "Objekt.h"
enum TypPrekazky {
	Skala, MalaRostlina, VelkaRostlina
};
struct StatickyObjekt : Objekt{
private:
	TypPrekazky typPrekazky;
public:
	StatickyObjekt(int id, TypPrekazky typPrekazky);
	TypPrekazky getTypPrekazky();
};

