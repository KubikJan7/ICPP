#ifndef _ADRESA_H
#define _ADRESA_H
#include<string>
struct Adresa {
	std::string _ulice;
	std::string _mesto;
	int _psc;

	Adresa(std::string ulice, std::string mesto, int psc);
	Adresa();
};

#endif