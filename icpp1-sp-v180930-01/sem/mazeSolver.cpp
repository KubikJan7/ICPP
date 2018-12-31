#include"mazeSolver.h"

MazeSolver::MazeSolver(Maze* m) {
	this->maze = m;
	this->dynArray = new DynArray<Point>;
	this->hashSet = new HashSet<Point, Point::Hash, Point::Equals>;
	this->linkedList = new LinkedList<Point>;
}

MazeSolver::~MazeSolver() {

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


