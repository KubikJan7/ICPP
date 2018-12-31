#include"mazeSolver.h"
#include"fstream"
#include <iostream>
using namespace std;

MazeSolver::MazeSolver(Maze* m) {
	this->maze = m;
	this->dynArray = new DynArray<Point>;
	this->hashSet = new HashSet<Point, Point::Hash, Point::Equals>(10);
	this->linkedList = new LinkedList<Point>;
}

MazeSolver::~MazeSolver() {
	delete dynArray;
	delete hashSet;
	delete linkedList;
}

// Vyøeš bludištì
	// - vrací true pokud má bludištì øešení, false pokud bludištì není øešitelné
	// - prohledávání zaèíná v bodì maze::getStart, prohledávání je ukonèeno, pokud není možné
	//   dále pokraèovat nebo bylo dosaženo cíle (maze::getEnd)
	// - v bludišti je možné se pohybovat 4 smìry: NAHORU (y-1), DOLÙ (y+1), DOLEVA (x-1) nebo DOPRAVA (x+1)
	// - v prùbìhu hledání cíle nemá smysl vstupovat na pole, která již byla navštívena
	//
	// - doporuèená strategie pro prohledávání je prohledávání do hloubky, cyklus:
	// -- zaznamenám aktuální polohu hledaèe do spojového seznamu (zároveò je bod zaznamenán do tabulky IHashSet)
	// -- vyberu jeden dostupný smìr a udìlám krok
	// -- pokud jsem na konci chodby a není možné dále pokraèovat - provedu odrolování
	// 
	// - odrolování - je použito, pokud není možné pokraèovat v další cestì
	// -- pro odrolování je použit v pøedchozím kroku vytváøený spojový seznam
	// -- cyklus: postupnì jsou odebírány jednotlivé prvky (od konce) ze spojového seznamu
	// ---- každý prvek seznamu obsahuje zaznamenanou polohu bodu
	// ---- pro každý prvek je otestováno, jestli existuje z daného bodu dostupná (dosud nenavštívená) cesta
	// ------ pokud je cesta pøítomna, je odrolování ukonèeno a algoritmus pokraèuje nalezenou cestou
	// ------ pokud není cesta dostupná, prvek je odebrán ze spojového seznamu
	// ---- pokud je spojový seznam vyprázdnìn a není nalezena další cesta -> bludištì nemá øešení
bool MazeSolver::solve() {
	IDynArray<Point>* possMoves = new DynArray<Point>;
	Point currPoint = maze->getStart();
	saveState(currPoint);
	hashSet->add(currPoint);
	while (!Point::Equals(currPoint, maze->getEnd())) {
		possMoves = dropMovesInAllPaths(getPossibleMoves(currPoint));
		if (possMoves->count() == 0)
			return true;
		currPoint = possMoves->get(0);
		saveState(currPoint);
		hashSet->add(currPoint);
		cout << currPoint.x << " " << currPoint.y << endl;

	}
	return true;
}
void MazeSolver::saveMazeAndSolution(std::string filename) const {
	ofstream out{};
	out.open(filename);
	if (out.is_open())
	{
		for (int i = 0; i < maze->getR(); i++) {
			for (int j = 0; j < maze->getC(); j++) {
				if(linkedList->isInList(Point(j, i)))
					out << '+';
				else if (maze->getPoint(Point(j, i)) == '.')
					out << ' ';
				else
					out << maze->getPoint(Point(j,i));
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
		cout << "Soubor se nepodarilo otevrit..."<<endl;
	}
}
// Funkce vrací pole všech dostupných krokù z daného výchozího místa
	// - krokem se rozumí pohyb NAHORU, DOLÙ, DOLEVA nebo DOPRAVA
	// - dané místo nesmí pøedstavovat zeï v bludišti a nesmí být mimo rozsah bludištì
	// - funkce neøeší, jestli místo bylo navštíveno nebo ne. 
IDynArray<Point>* MazeSolver::getPossibleMoves(Point pt) const {
	IDynArray<Point>* ar = new DynArray<Point>;
	Point up = Point{ pt.x,pt.y - 1 };
	Point down = Point{ pt.x,pt.y + 1 };
	Point left = Point{ pt.x - 1,pt.y };
	Point right = Point{ pt.x + 1,pt.y };
	Point points[] = { up,down,left,right };
	for (Point p : points) {
		if (maze->getPoint(p) != NULL &&maze->getPoint(p) != '#') {
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


