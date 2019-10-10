#ifndef MAZE_H
#define MAZE_H

#include"interfaces.h"
struct Maze : public IMaze {
private:
	int pocet_radku;
	int pocet_sloupcu;
	int x_vstupu;
	int y_vstupu;
	int x_vystupu;
	int y_vystupu;
	Point** data;

public:
	virtual ~Maze();
	Maze(int pocet_radku, int pocet_sloupcu, int x_vstupu, int y_vstupu, int x_vystupu, int y_vystupu, Point** data);
	static Maze* fromFile(std::string filename);
	virtual bool isValidPoint(Point pt) const;
	virtual char getPoint(Point pt) const;
	virtual int getR() const;
	virtual int getC() const;
	virtual Point getStart() const;
	virtual Point getEnd() const;
};
#endif