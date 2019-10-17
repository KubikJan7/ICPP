#ifndef IObject_H
#define IObject_H
#include <iostream>

struct IObject {
	virtual ~IObject() {}
	virtual std::string toString() const = 0;
};

#endif