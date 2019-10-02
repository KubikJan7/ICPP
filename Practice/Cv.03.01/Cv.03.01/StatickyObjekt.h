#include "Objekt.h"
struct StatickyObjekt {
	TypPrekazky typPrekazky;
	StatickyObjekt(int id, TypPrekazky typPrekazky);
	TypPrekazky getTypPrekazky();
};
struct Objekt :StatickyObjekt {
};
enum TypPrekazky {
	Skala, MalaRostlina, VelkaRostlina
};