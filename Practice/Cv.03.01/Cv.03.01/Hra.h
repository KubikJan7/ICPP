#include"Objekt.h"
#include "PohyblivyObjekt.h"

struct Hra {
private:
	Objekt** objekty;
	int hp;
	int maxhp;

public:
	void setHp(int hp);
	int getHp();

	void setMaxHp(int maxHp);
	int getMaxHp();

	void vlozObjekt(Objekt* o);
	int* najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r);
	PohyblivyObjekt** najsiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax);
};