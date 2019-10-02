// Cv01.cpp: Definuje vstupní bod pro konzolovou aplikaci.
//

#include "stdafx.h"
/*#include <cstdio>
#include <cstdlib>*/
#include <iostream>

using namespace std;

int main()
{
	/*std::*/cout << "Hello" <<" "<<"world"<<"!"<<" "<<123456<<123.456<< endl;

	int* ukazatel = nullptr;
	ukazatel = new int; //malloc(sizeof(int))
	*ukazatel = 123456;
	cout << "ukazatel" << endl;

	delete ukazatel; //free(ukazatel)

	
	/*int cislo;
	cin >> cislo;
	cout << "Nacetl jsem:" << cislo << endl;
	*/
	int tmp;
	cin >> tmp;
	/*printf("Hello world/n");
	system("pause");*/
    return 0;
}

