#ifndef DOG_H
#define DOG_H
#include "Animal.h"
struct Dog : Animal
{
public:
	Dog(int legCount) { this->legCount = legCount; }
	virtual std::string MakeSound() override;
};
#endif
