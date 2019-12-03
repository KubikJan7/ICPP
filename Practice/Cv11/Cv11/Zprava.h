#ifndef ZPRAVA_H
#define ZPRAVA_H

#include <string>

struct Zprava {
	int id;
	std::string adrZdroj;
	std::string adrCil;
	std::string obsah;
};

#endif