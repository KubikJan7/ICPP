#include"IComparable.h"
struct Cas:IComparable {
private:
	int _hodiny;
	int _minuty;
	int _sekundy;
public:
	Cas(int _hodiny, int _minuty, int _sekundy); 
};