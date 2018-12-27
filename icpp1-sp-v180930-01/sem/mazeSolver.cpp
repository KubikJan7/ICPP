#include"mazeSolver.h"

MazeSolver::MazeSolver(Maze* m) {

}

MazeSolver::~MazeSolver() {

}
bool MazeSolver::solve() {
	return false;
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
	return false;
}
bool MazeSolver::isInAllHistory(Point pt) const {
	return false;
}
void MazeSolver::saveState(Point pt) {

}
IMaze* MazeSolver::getMaze() const {
	IMaze* m = nullptr;
	return m;
}

