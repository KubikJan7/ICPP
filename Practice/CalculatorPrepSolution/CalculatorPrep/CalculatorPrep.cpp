
#include <iostream>
#include "Kalkulator.h"
#include "VyjimkaKalkulatoru.h"

using namespace std;
int main()
{
	try {
		Kalkulator<double, 2> k{ 10 };
		k.pridejHodnotu(2);
		k.pridejOperator('+');
		k.pridejHodnotu(3);
		k.pridejOperator('*');
		k.pridejHodnotu(5);
		cout << k.vypocitej() << endl;
	}
	catch (VyjimkaKalkulatoru v)
	{
		cout << v.getMessage() << endl;
	}
}


