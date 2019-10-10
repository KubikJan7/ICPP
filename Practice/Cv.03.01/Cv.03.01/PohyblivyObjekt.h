#pragma once
#include "Objekt.h"
struct PohyblivyObjekt :Objekt{
private:
	double uhelNatoceni;
public:
	void setUhelNatoceni(double uhelNatoceni);
	double getUhelNatoceni();
	PohyblivyObjekt();
};