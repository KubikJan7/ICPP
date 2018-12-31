#include "interfaces.h"
#ifndef __POINT_H
#define __POINT_H

// EDITOVATELN� SOUBOR

struct Point {

	// ve�ejn� p��stupn� atributy:
	// - celo��seln� datov� slo�ky x, y
public:
	Point(){}
	Point(int x, int y);
	Point(int x, int y,char prvek);
	~Point(){}
	// statick� metoda Hash, vyhovuj�c� typu HashFunction<Point>
	// - metoda pou�ita pro hash mno�inu
	// - vypo��t� hash jako: h(point) = 11 * point[x] + point[y]
	static int Hash(const Point& p);
	// statick� metoda Equals, vyhovuj�c� typu EqualFunction<Point>
	// - metoda pou�ita pro hash mno�inu
	// - vrac� true, pokud dva body maj� shodn� ob� sou�adnice
	static bool Equals(const Point &p1,const Point &p2);
	int x;
	int y;
	char prvek;
};

#endif