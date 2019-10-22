#ifndef ENTITY_H
#define ENTITY_H

#include <string>

namespace Entity {
	struct Osoba {
		std::string jmeno;
		std::string telefon;
		int id;

		Osoba();
		Osoba(std::string jmeno, std::string telefon, int id);
	};
}
#endif