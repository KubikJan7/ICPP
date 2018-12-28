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
int Point::Hash(Point p) {
	return 0;
}
bool Point::Equals(Point p1, Point p2) {
	return true;
}