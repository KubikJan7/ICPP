#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
struct Animal
{
public:
	int legCount;

public:
	virtual std::string MakeSound() { return "default"; }
};
#endif

