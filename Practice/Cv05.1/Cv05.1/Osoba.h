#ifndef ENTITY_H
#define ENTITY_H

#include <string>
using namespace std;

namespace Entity {
	struct Osoba {
		string jmeno;
		string telefon;
		int id;

		Osoba() : jmeno(""), telefon(""), id(0) {}
	};
}
#endif