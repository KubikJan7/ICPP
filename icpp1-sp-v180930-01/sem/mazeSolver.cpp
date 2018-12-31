#include"mazeSolver.h"
#include"fstream"
using namespace std;

MazeSolver::MazeSolver(Maze* m) {
	this->maze = m;
	this->dynArray = new DynArray<Point>;
	this->hashSet = new HashSet<Point, Point::Hash, Point::Equals>;
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


	return true;
}
void MazeSolver::saveMazeAndSolution(std::string filename) const {
	ofstream out{};
	out.open(filename);

	if (out.is_open())
	{
		for (int i = 0; i < maze->getR(); i++) {
			for (int j = 0; j < maze->getC(); j++) {
				out << maze->getPoint(Point(j,i));
			}
			out << endl;
		}

		out.close();
	}
	else
		throw("Soubor se nepodarilo otevrit...");
}
// Funkce vrací pole všech dostupných krokù z daného výchozího místa
	// - krokem se rozumí pohyb NAHORU, DOLÙ, DOLEVA nebo DOPRAVA
	// - dané místo nesmí pøedstavovat zeï v bludišti a nesmí být mimo rozsah bludištì
	// - funkce neøeší, jestli místo bylo navštíveno nebo ne. 
DynArray<Point>* MazeSolver::getPossibleMoves(Point pt) const {
	DynArray<Point>* ar = new DynArray<Point>;
	Point up = Point{ pt.x,pt.y - 1 };
	Point down = Point{ pt.x,pt.y + 1 };
	Point left = Point{ pt.x - 1,pt.y };
	Point right = Point{ pt.x + 1,pt.y };
	Point points[] = { up,down,left,right };
	for (Point p : points) {
		if (maze->getPoint(p) != '#'&&p.x > 0 && p.x < maze->getC() && p.y>0 && p.y < maze->getR()) {
			ar->add(p);
		}
	}
	return ar;
}
IDynArray<Point>* MazeSolver::dropMovesInAllPaths(IDynArray<Point>* moves) const {
	IDynArray<Point>* newAr = new DynArray<Point>;
	for (int i = 0; i < moves->count(); i++) {
		if (!hashSet->isPresent(moves->get(i))) {
			newAr[newAr->count()] = moves[i];
		}
	}
	return dynArray;
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


