
#include <iostream>
#include "Cas.h"
#include "Datum.h"
#include "DatumCas.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void SeraditPole(IComparable** pole, int velikostPole) {
	IComparable* pom;
	for (int i = 0; i < velikostPole - 1; i++) {
		for (int j = 0; j < velikostPole - i - 1; j++) {
			if (pole[j]->compareTo(pole[j + 1])==1) {
				pom = pole[j];
				pole[j] = pole[j + 1];
				pole[j + 1] = pom;
			}
		}
	}
}

int main()
{
	IComparable** poleUk = new IComparable * [10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		poleUk[i] = new Cas{ rand()%24,rand()%60,rand()%60};
	}

	/*Datum* d1 = new Datum{ 1920,5,3 };
	Datum* d2 = new Datum{ 2019,12,3 };

	DatumCas* dc1 = new DatumCas(d1, c2);
	DatumCas* dc2 = new DatumCas(d2,c3);*/
	SeraditPole(poleUk, 10);
	cout << poleUk[0]->compareTo(poleUk[1]) << endl;
	cout << dynamic_cast<Cas*>(poleUk[0])->_hodiny << endl;
}


