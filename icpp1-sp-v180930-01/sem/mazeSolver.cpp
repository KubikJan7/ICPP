#include"mazeSolver.h"

MazeSolver::MazeSolver(Maze* m) {
	this->maze = m;
	this->dynArray = new DynArray<Point>;
	this->hashSet = new HashSet<Point, Point::Hash, Point::Equals>;
	this->linkedList = new LinkedList<Point>;
}

MazeSolver::~MazeSolver() {

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
	return true;
}
void MazeSolver::saveMazeAndSolution(std::string filename) const {

}
DynArray<Point>* MazeSolver::getPossibleMoves(Point pt) const{
	DynArray<Point>* pole = nullptr;
	return pole;
}
DynArray<Point>* MazeSolver::dropMovesInAllPaths(IDynArray<Point>* moves) const {
	return dynArray;
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


