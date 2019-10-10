#include "Hra.h"
#include "StatickyObjekt.h"
#include <typeinfo>
#include <iostream>
Hra::Hra(int velikostPoleObjektu)
{
	this->velikostPoleObjektu = velikostPoleObjektu;
	this->pocetObjektu = 0;
	objekty = new Objekt * [velikostPoleObjektu];
}

void Hra::vlozObjekt(Objekt* o) {
	objekty[pocetObjektu++] = o;
}
int* Hra::najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax) {
	int* poleId = new int[pocetObjektu]();
	int pocetId = 0;
	for (int i = 0; i < pocetObjektu; i++)
	{
		double oX = objekty[i]->getX();
		double oY = objekty[i]->getY();
		if (typeid(*objekty[i]) == typeid(StatickyObjekt) && oX >= xmin && oX <= xmax && oY >= ymin && oY <= ymax) {
			poleId[pocetId++] = objekty[i]->getId();
		}
	}
	return resizeArray(poleId,pocetId);
}
int velikost;
PohyblivyObjekt** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r) {
	PohyblivyObjekt** objektyOblasti = new PohyblivyObjekt * [pocetObjektu];
	int pocetOb = 0;
	for (int i = 0; i < pocetObjektu; i++)
	{
		double oX = objekty[i]->getX();
		double oY = objekty[i]->getY();
		if (typeid(objekty[i]) == typeid(PohyblivyObjekt) && !(((oX - x) * (oX - x) + (oY - y) * (oY - y)) > (r * r)))
			objektyOblasti[pocetOb++] = (PohyblivyObjekt*)objekty[i];
	}
	velikost = pocetOb;
	return resizeArray(objektyOblasti, pocetOb);
}

PohyblivyObjekt** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax) {
	PohyblivyObjekt** objektyKruhu = najdiPohybliveObjektyVOblasti(x, y, r);
	PohyblivyObjekt** objektyOblasti = new PohyblivyObjekt * [velikost];
	int pocetObjObl = 0;
	for (int i = 0; i < velikost; i++)
	{
		if (objektyKruhu[i]->getUhelNatoceni() >= umin && objektyKruhu[i]->getUhelNatoceni() <= umax)
			objektyOblasti[pocetObjObl++] = objektyKruhu[i];
	}
	delete[] objektyKruhu;
	return resizeArray(objektyOblasti,pocetObjObl);
}
int Hra::getPocetObjektu()
{
	return pocetObjektu;
}
PohyblivyObjekt** Hra::resizeArray(PohyblivyObjekt**& pole, int pocetPrvku)
{
	PohyblivyObjekt** newArray = new PohyblivyObjekt * [pocetPrvku];
	int i = 0;
	for (int i = 0; i < pocetPrvku; i++)
	{
		newArray[i] = pole[i];
	}
	delete[] pole;
	return newArray;
}

int* Hra::resizeArray(int*& pole, int pocetPrvku)
{
	int* newArray = new int [pocetPrvku];
	int i = 0;
	for (int i = 0; i < pocetPrvku; i++)
	{
		newArray[i] = pole[i];
	}
	delete[] pole;
	return newArray;
}
