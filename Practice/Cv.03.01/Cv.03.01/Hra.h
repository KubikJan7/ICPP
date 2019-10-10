#pragma once
#include"Objekt.h"
#include "PohyblivyObjekt.h"

struct Hra {
private:
	Objekt** objekty;
	int pocetObjektu;
	int velikostPoleObjektu;
	PohyblivyObjekt** resizeArray(PohyblivyObjekt**& pole, int pocetPrvku);
	int* resizeArray(int*& pole,int pocetPrvku);
public:
	Hra(int velikostPoleObjektu);
	void vlozObjekt(Objekt* o);
	int* najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax);
	int getPocetObjektu();
};