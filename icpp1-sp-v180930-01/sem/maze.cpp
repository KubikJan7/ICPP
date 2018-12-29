#include "maze.h"
#include <iostream>
#include <fstream>
using namespace std;

Maze::~Maze() {

}
Maze* Maze::fromFile(string filename) {
	int pocetR, pocetS, startX, startY, endX, endY;
	Point** prvky;
	char ch;
	ifstream in{};
	in.open(filename);

	if (in.is_open())
	{
		in >> pocetR; in >> pocetS; in >> startY; in >> startX; in >> endY; in >> endX;
		prvky = new Point*[pocetR];
		for (int i = 0; i < pocetR; i++) {
			prvky[i] = new Point[pocetS];
			for (int j = 0; j < pocetS; j++) {
				in >> ch;
				prvky[i][j] = Point{i, j, ch};
			}
		}
	}
	in.close();
	/*for (int i = 0; i < pocetR; i++) {
		for (int j = 0; j < pocetS; j++) {
			cout<<prvky[i][j].prvek;
		}
		cout << endl;
	}*/
	return new Maze{ pocetR,pocetS,startX,startY,endX,endY,prvky };
}
bool Maze::isValidPoint(Point pt) const {
	return true;
}
char Maze::getPoint(Point pt) const {
	try {
		for (int i = 0; i < pocet_radku; i++) {
			for (int j = 0; j < pocet_sloupcu; j++) {
				if (i == pt.y && j == pt.x) {
					return data[i][j].prvek;
				}
			}
		}
	}
	catch(exception e){
		throw "Zadane souradnice nejsou platne";
	}
	return ' ';
}
int Maze::getR() const {
	return pocet_radku;
}
int Maze::getC() const {
	return pocet_sloupcu;
}
Point Maze::getStart() const {
	Point p{ x_vstupu,y_vstupu };
	return p;
}
Point Maze::getEnd() const {
	Point p{ x_vystupu,y_vystupu };
	return p;
}
Maze::Maze(int pocet_radku, int pocet_sloupcu, int x_vstupu, int y_vstupu, int x_vystupu, int y_vystupu, Point** data) {
	this->pocet_radku = pocet_radku;
	this->pocet_sloupcu = pocet_sloupcu;
	this->x_vstupu = x_vstupu;
	this->y_vstupu = y_vstupu;
	this->x_vystupu = x_vystupu;
	this->y_vystupu = y_vystupu;
	this->data = data;
}