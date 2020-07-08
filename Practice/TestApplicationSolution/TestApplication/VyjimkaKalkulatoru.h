#ifndef VYJIMKA_KALKULATORU_H
#define VYJIMKA_KALKULATORU_H

#include <string>

struct VyjimkaKalkulatoru
{
private:
	std::string message;
public:
	VyjimkaKalkulatoru(std::string message) : message(message) {}
	std::string getMessage() { return message; };
};

#endif