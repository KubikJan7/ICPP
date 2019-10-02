
#include <iostream>
#include <string>
using namespace std;

struct Zvire {

public:
	struct Zvire(string typ, string rad) {

	};
};
struct Medved : Zvire {
	Medved() : Zvire(("obratlovec", "medvedovity")) {

	}

	void udelejBuuu() {

	}
};
int main()
{
	Medved medved{};
	Zvire* zvirePtr = new Medved{};
	Zvire& zvireRef = *(new Medved{});

	Medved* meda = dynamic_cast<Medved*>(zvirePtr);
	if (meda != nullptr) {
		meda->udelejBuuu();
	}
	return 0;
}
