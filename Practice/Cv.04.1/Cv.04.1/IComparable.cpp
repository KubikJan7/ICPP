#include "IComparable.h"
using namespace std;
int IComparable::compareTo(IComparable* obj) const {
	if (this == obj) {
		cout << "Rovnaji se" << endl;
		return 0;
	}
	else if (this < obj) {
		cout << "Prvni je mensi" << endl;
		return -1;
	}
	else if (this > obj) {
		cout << "Prvni je vetsi" << endl;
		return 1;
	}
}