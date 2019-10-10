#include"PohyblivyObjekt.h"

void PohyblivyObjekt::setUhelNatoceni(double uhelNatoceni) {
	this->uhelNatoceni = uhelNatoceni;
}
double PohyblivyObjekt::getUhelNatoceni() {
	return uhelNatoceni;
}

PohyblivyObjekt::PohyblivyObjekt():Objekt(-1)
{
	uhelNatoceni = 0;
}

