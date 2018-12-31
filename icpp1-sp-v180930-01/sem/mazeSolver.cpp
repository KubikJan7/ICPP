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

// Vy�e� bludi�t�
	// - vrac� true pokud m� bludi�t� �e�en�, false pokud bludi�t� nen� �e�iteln�
	// - prohled�v�n� za��n� v bod� maze::getStart, prohled�v�n� je ukon�eno, pokud nen� mo�n�
	//   d�le pokra�ovat nebo bylo dosa�eno c�le (maze::getEnd)
	// - v bludi�ti je mo�n� se pohybovat 4 sm�ry: NAHORU (y-1), DOL� (y+1), DOLEVA (x-1) nebo DOPRAVA (x+1)
	// - v pr�b�hu hled�n� c�le nem� smysl vstupovat na pole, kter� ji� byla nav�t�vena
	//
	// - doporu�en� strategie pro prohled�v�n� je prohled�v�n� do hloubky, cyklus:
	// -- zaznamen�m aktu�ln� polohu hleda�e do spojov�ho seznamu (z�rove� je bod zaznamen�n do tabulky IHashSet)
	// -- vyberu jeden dostupn� sm�r a ud�l�m krok
	// -- pokud jsem na konci chodby a nen� mo�n� d�le pokra�ovat - provedu odrolov�n�
	// 
	// - odrolov�n� - je pou�ito, pokud nen� mo�n� pokra�ovat v dal�� cest�
	// -- pro odrolov�n� je pou�it v p�edchoz�m kroku vytv��en� spojov� seznam
	// -- cyklus: postupn� jsou odeb�r�ny jednotliv� prvky (od konce) ze spojov�ho seznamu
	// ---- ka�d� prvek seznamu obsahuje zaznamenanou polohu bodu
	// ---- pro ka�d� prvek je otestov�no, jestli existuje z dan�ho bodu dostupn� (dosud nenav�t�ven�) cesta
	// ------ pokud je cesta p��tomna, je odrolov�n� ukon�eno a algoritmus pokra�uje nalezenou cestou
	// ------ pokud nen� cesta dostupn�, prvek je odebr�n ze spojov�ho seznamu
	// ---- pokud je spojov� seznam vypr�zdn�n a nen� nalezena dal�� cesta -> bludi�t� nem� �e�en�
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
// Funkce vrac� pole v�ech dostupn�ch krok� z dan�ho v�choz�ho m�sta
	// - krokem se rozum� pohyb NAHORU, DOL�, DOLEVA nebo DOPRAVA
	// - dan� m�sto nesm� p�edstavovat ze� v bludi�ti a nesm� b�t mimo rozsah bludi�t�
	// - funkce ne�e��, jestli m�sto bylo nav�t�veno nebo ne. 
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


