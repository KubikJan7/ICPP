
struct Objekt{
private:
	int id;
	double x;
	double y;

	Objekt(int id);
	virtual ~Objekt();
public:
	void setX();
	void setY();
	double getX();
	double getY();
	int getId();
};