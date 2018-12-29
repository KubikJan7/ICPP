#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include"maze.h"
struct MazeSolver : public IMazeSolver {
public:
	virtual ~MazeSolver();
	MazeSolver(Maze* m);
	virtual bool solve();
	virtual void saveMazeAndSolution(std::string filename) const;
	virtual IDynArray<Point>* getPossibleMoves(Point pt) const;
	virtual IDynArray<Point>* dropMovesInAllPaths(IDynArray<Point>* moves) const;
	virtual bool isInCurrentHistory(Point pt) const;
	virtual bool isInAllHistory(Point pt) const;
	virtual void saveState(Point pt);
	virtual Maze* getMaze() const;
private:
	Maze* maze;
};
#endif