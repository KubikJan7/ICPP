// CV02.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Uctenka.h"
#include "Pokladna.h"
int main()
{
	Pokladna p{};

	Uctenka& u1 = p.vystavUctenku(100, 0.22);
	Uctenka& u2 = p.vystavUctenku(200, 0.22);
	Uctenka& u3 = p.vystavUctenku(300, 0.22);

	u1.setCastka(1000);

	u1.precistUctenku();
	u2.precistUctenku();
	u3.precistUctenku();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
