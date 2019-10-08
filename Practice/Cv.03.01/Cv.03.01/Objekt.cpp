#include "Objekt.h"

Objekt::Objekt(int id) {
	this->id = id;
	this->x = 0;
	this->y = 0;
}
Objekt::Objekt(int id, int x, int y) {
	this->id = id;
	this->x = x;
	this->y = y;
}
Objekt:: ~Objekt() {

}

void Objekt::setX(double x)
{
	this->x = x;
}

double Objekt::getX()
{
	return x;
}

void Objekt::setY(double y)
{
	this->y = y;
}

double Objekt::getY()
{
	return y;
}

int Objekt::getId()
{
	return id;
}
