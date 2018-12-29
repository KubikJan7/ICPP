#include"mazeSolver.h"

MazeSolver::MazeSolver(Maze* m) {
	this->maze = m;
}

MazeSolver::~MazeSolver() {

}
bool MazeSolver::solve() {
	return true;
}
void MazeSolver::saveMazeAndSolution(std::string filename) const {

}
IDynArray<Point>* MazeSolver::getPossibleMoves(Point pt) const{
	IDynArray<Point>* pole = nullptr;
	return pole;
}
IDynArray<Point>* MazeSolver::dropMovesInAllPaths(IDynArray<Point>* moves) const {
	return moves;
}
bool MazeSolver::isInCurrentHistory(Point pt) const {
	return true;
}
bool MazeSolver::isInAllHistory(Point pt) const {
	return true;
}
void MazeSolver::saveState(Point pt) {

}
Maze* MazeSolver::getMaze() const {
	return maze;
}

