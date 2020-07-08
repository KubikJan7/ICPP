#ifndef CAT_H
#define CAT_H

#include "Animal.h"

struct Cat : Animal
{
public:
	Cat(int legCount) { this->legCount = legCount; }
	virtual std::string MakeSound() override;
	std::string purr();
};
#endif