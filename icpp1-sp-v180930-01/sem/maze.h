#ifndef MAZE_H
#define MAZE_H

#include"interfaces.h"
struct Maze : public IMaze {

	virtual ~Maze();
	static Maze* fromFile(std::string filename);
	virtual bool isValidPoint(Point pt) const;
	virtual char getPoint(Point pt) const;
	virtual int getR() const;
	virtual int getC() const;
	virtual Point getStart() const;
	virtual Point getEnd() const;
};
#endif