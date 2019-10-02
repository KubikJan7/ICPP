// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	//int* ukazatel = new int{ 0 };
	//double* ukazatelDouble = new double{ 0 };
	int* pole = new int[10];
	for (int i = 0; i < 10; i++)
	{
		pole[i] = i * 2;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << pole[i] << " " << *(pole + i) << endl;
	}
	
	delete[] pole;

	/*cout << "Ukazatel ukazuje na adresu: " << ukazatel << endl;
	cout << "Ukazatel ukazuje na hodnotu: " << *ukazatel << endl;
	cout << "Ukazatel se nachati na adrese: " << &ukazatel << endl;

	cout << endl;

	cout << "UkazatelDouble ukazuje na adresu: " << ukazatelDouble << endl;
	cout << "UkazatelDouble ukazuje na hodnotu: " << *ukazatelDouble << endl;
	cout << "UkazatelDouble se nachati na adrese: " << &ukazatelDouble << endl;

	delete ukazatel;
	delete ukazatelDouble;*/

	/*int i = 123548;
	double pi = 3.1415;
	bool b = true;

	cout << hex << i << dec<<endl;
	cout << i << " " << pi << " " << b << endl;*/

	/*cout << "Zadej cislo" << endl;
	int cislo;
	cin >> cislo;

	cout << "Zadal jsi: " << cislo<<endl;*/
	system("Pause");
}
