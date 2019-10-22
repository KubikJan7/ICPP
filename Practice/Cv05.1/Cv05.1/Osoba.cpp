#include "Osoba.h"

Entity::Osoba::Osoba() : jmeno(""), telefon(""),id(0)
{
}

Entity::Osoba::Osoba(std::string jmeno, std::string telefon, int id)
{
	this->jmeno = jmeno;
	this->telefon = telefon;
	this->id = id;
}
