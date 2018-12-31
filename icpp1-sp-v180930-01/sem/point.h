#include "interfaces.h"
#ifndef __POINT_H
#define __POINT_H

// EDITOVATELNÝ SOUBOR

struct Point {
public:
	Point(){}
	Point(int x, int y);
	Point(int x, int y,char prvek);
	~Point(){}
	static int Hash(const Point& p);
	static bool Equals(const Point &p1,const Point &p2);

	int x;
	int y;
	char prvek;
};

#endif