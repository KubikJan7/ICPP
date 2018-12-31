#include "point.h"
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}
Point::Point(int x, int y, char prvek) {
	this->x = x;
	this->y = y;
	this->prvek = prvek;
}
int Point::Hash(const Point& p) {
	return 11 * p.x + p.y;
}
bool Point::Equals(const Point &p1, const Point &p2) {
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	else
		return false;
}