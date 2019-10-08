#include "StatickyObjekt.h"
#include <iostream>
StatickyObjekt::StatickyObjekt(int id, TypPrekazky typPrekazky):Objekt(id) {
	this->id = id;
	this->typPrekazky = typPrekazky;
}
TypPrekazky StatickyObjekt::getTypPrekazky() {
	return typPrekazky;
}