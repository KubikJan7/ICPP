# pragma once
struct Objekt{
public:
	int id;
	double x;
	double y;
	Objekt(int id);
	Objekt(int id, int x, int y);
	virtual ~Objekt();
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	int getId();
	
};