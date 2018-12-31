#include "interfaces.h"
#ifndef __POINT_H
#define __POINT_H

// EDITOVATELNÝ SOUBOR

struct Point {

	// veøejnì pøístupné atributy:
	// - celoèíselné datové složky x, y
public:
	Point(){}
	Point(int x, int y);
	Point(int x, int y,char prvek);
	~Point(){}
	// statická metoda Hash, vyhovující typu HashFunction<Point>
	// - metoda použita pro hash množinu
	// - vypoèítá hash jako: h(point) = 11 * point[x] + point[y]
	static int Hash(const Point& p);
	// statická metoda Equals, vyhovující typu EqualFunction<Point>
	// - metoda použita pro hash množinu
	// - vrací true, pokud dva body mají shodné obì souøadnice
	static bool Equals(const Point &p1,const Point &p2);
	int x;
	int y;
	char prvek;
};

#endif