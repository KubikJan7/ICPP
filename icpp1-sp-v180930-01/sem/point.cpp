#include "point.h"
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}
Point::Point(int x, int y,char prvek) {
	this->x = x;
	this->y = y;
	this->prvek = prvek;
}
int Point::Hash(const Point& p) {
	return 0;
}
bool Point::Equals(const Point &p1, const Point &p2) {
	return true;
}