#include"mazeSolver.h"
#include"fstream"
#include <iostream>
using namespace std;

MazeSolver::MazeSolver(Maze* m) {
	this->maze = m;
	this->hashSet = new HashSet<Point, Point::Hash, Point::Equal>(10);
	this->linkedList = new LinkedList<Point>;
}

MazeSolver::~MazeSolver() {
	delete hashSet;
	delete linkedList;
}

bool MazeSolver::solve() {
	IDynArray<Point>* possMoves = new DynArray<Point>;
	Point currPoint = maze->getStart();
	saveState(currPoint);
	hashSet->add(currPoint);
	show();
	while (!Point::Equal(currPoint, maze->getEnd())) {
		possMoves = dropMovesInAllPaths(getPossibleMoves(currPoint));
		if (possMoves->count() == 0) {
			linkedList->deleteLast();
			if (linkedList->isEmpty())
				return false;
			currPoint = linkedList->getPeak();
			continue;
			
		}
		currPoint = possMoves->get(0);
		saveState(currPoint);
		hashSet->add(currPoint);
		show();
	}
	delete possMoves;
	return true;
}
void MazeSolver::saveMazeAndSolution(std::string filename) const {
	ofstream out{};
	out.open(filename);
	if (out.is_open())
	{
		for (int i = 0; i < maze->getR(); i++) {
			for (int j = 0; j < maze->getC(); j++) {
				if (linkedList->isInList(Point(j, i)))
					out << '+';
				else if (maze->getPoint(Point(j, i)) == '.')
					out << ' ';
				else
					out << maze->getPoint(Point(j, i));
			}
			out << endl;
		}

		out.close();
	}
	else
		try {
		throw("error");
	}
	catch (...) {
		cout << "Soubor se nepodarilo otevrit..." << endl;
	}
}

IDynArray<Point>* MazeSolver::getPossibleMoves(Point pt) const {
	IDynArray<Point>* ar = new DynArray<Point>;
	Point up = Point{ pt.x,pt.y - 1 };
	Point down = Point{ pt.x,pt.y + 1 };
	Point left = Point{ pt.x - 1,pt.y };
	Point right = Point{ pt.x + 1,pt.y };
	Point points[] = { up,down,left,right };
	for (Point p : points) {
		if (maze->getPoint(p) != NULL && maze->getPoint(p) != '#') {
			ar->add(p);
		}
	}
	return ar;
}
IDynArray<Point>* MazeSolver::dropMovesInAllPaths(IDynArray<Point>* moves) const {
	IDynArray<Point>* newAr = new DynArray<Point>;
	for (int i = 0; i < moves->count(); i++) {
		if (!hashSet->isPresent(moves->get(i))) {
			newAr->add(moves->get(i));
		}
	}
	delete moves;
	return newAr;
}
bool MazeSolver::isInCurrentHistory(Point pt) const {
	return linkedList->isInList(pt);
}
bool MazeSolver::isInAllHistory(Point pt) const {
	return hashSet->isPresent(pt);
}
void MazeSolver::saveState(Point pt) {
	linkedList->insertLast(pt);
}
Maze* MazeSolver::getMaze() const {
	return maze;
}


