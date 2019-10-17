#ifndef IComparable_H
#define IComparable_H

#include "IObject.h"

struct IComparable:IObject {
	virtual ~IComparable() {}
	virtual int compareTo(IComparable* obj) const = 0;
};
#endif