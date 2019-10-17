
#include <iostream>
#include "Cas.h"

using namespace std;

void SeraditPole(IComparable** pole, int velikostPole) {
	IComparable *pom;
	for (int i = 0; i < velikostPole-1; i++) {
		for (int j = 0; j < velikostPole-i-1; j++) {
			if (pole[j] > pole[j + 1]) {
				pom = pole[j];
				pole[j] = pole[j + 1];
				pole[j + 1] = pom;
			}
		}
	}
}

int main()
{
	IComparable **poleUk = new IComparable*[10];
	poleUk[0] = new Cas(16,45,25);
	poleUk[1] = new Cas{ 10,23,21 };
	poleUk[2] = new Cas{ 23,25,18 };

	SeraditPole(poleUk, 3);
	
}


