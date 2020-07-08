#include <iostream>
#include "Kalkulator.h"
#include "VyjimkaKalkulatoru.h"

using namespace std;

int main()
{
	try {
		Kalkulator<double, 4> k{ 100 };
		k.pridejHodnotu(3);
		k.pridejOperator('+');
		k.pridejHodnotu(4);
		//k.pridejHodnotu(5);
		k.pridejOperator('/');
		k.pridejHodnotu(6);
		cout << "The final result is " << k.vypocitej() << "" << endl;
	}
	catch (VyjimkaKalkulatoru e)
	{
		cout << e.getMessage() << endl;
	}
}

