#include "Hra.h"
#include "StatickyObjekt.h"
#include <typeinfo>
Hra::Hra(int velikostPoleObjektu)
{
	this->velikostPoleObjektu = velikostPoleObjektu;
	this->pocetObjektu = 0;
	objekty = new Objekt * [velikostPoleObjektu];
}

void Hra::vlozObjekt(Objekt* o) {
	objekty[pocetObjektu] = o;
}
int* Hra::najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax) {
	int* poleId = new int[pocetObjektu];
	for (int i = 0; i < pocetObjektu; i++)
	{
		double oX = objekty[i]->getX();
		double oY = objekty[i]->getY();
		if (typeid(objekty[i]) == typeid(StatickyObjekt) && oX >= xmin && objekty && oY <= xmax && oY >= ymin && oY <= ymax) {}
	}
	return poleId;
}
PohyblivyObjekt** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r) {
	return new PohyblivyObjekt*;
}
PohyblivyObjekt** Hra::najsiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax) {
	return new PohyblivyObjekt*;
}