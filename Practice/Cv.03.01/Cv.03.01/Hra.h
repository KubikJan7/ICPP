#pragma once
#include"Objekt.h"
#include "PohyblivyObjekt.h"

struct Hra {
private:
	Objekt** objekty;
	int pocetObjektu;
	int velikostPoleObjektu;
public:
	Hra(int velikostPoleObjektu);
	void vlozObjekt(Objekt* o);
	int* najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r);
	PohyblivyObjekt** najsiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax);
};