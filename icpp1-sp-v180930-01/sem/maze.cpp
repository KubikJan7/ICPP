#include "maze.h"

Maze::~Maze() {

}
Maze* Maze::fromFile(std::string filename) {
	Maze* m = nullptr;
	return m;
}
bool Maze::isValidPoint(Point pt) const {
	return false;
}
char Maze::getPoint(Point pt) const {
	char c = 'a';
	return c;
}
int Maze::getR() const {
	return 0;
}
int Maze::getC() const {
	return 0;
}
Point Maze::getStart() const {
	Point p(0,0);
	return p;
}
Point Maze::getEnd() const {
	Point p(0, 0);
	return p;
}