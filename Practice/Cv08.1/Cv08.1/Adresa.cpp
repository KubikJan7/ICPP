#include"Adresa.h"
#include<iostream>
Adresa::Adresa(std::string ulice, std::string mesto, int psc) {
	_ulice = ulice;
	_mesto = mesto;
	_psc = psc;
}

Adresa::Adresa() : _ulice(""), _mesto(""), _psc(0) {

}