#include <iostream>

struct IObject {
	virtual ~IObject() {}
	virtual std::string toString() const = 0;
};