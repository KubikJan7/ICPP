// Cv020.cpp: Definuje vstupní bod pro konzolovou aplikaci.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "pes.h"

using namespace std;

int main()
{

	/* Kocka micka(); - ne
	   Kocka micka; - ano
	   Kocka micka ("Micka") - ano
	   Kocka micka{} - ano
	   Kocka micka{"Micka} - ano*/
	Pes alik("Alik");
	alik.stekej();

	Pes* rex = nullptr;
	rex = new Pes{ "Rex" };
	rex->stekej();
	delete rex;

	rex->vypisPocetPsu();
	system("Pause");
    return 0;
}

