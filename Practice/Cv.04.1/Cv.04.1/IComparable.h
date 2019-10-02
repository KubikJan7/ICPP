#include "IObject.h"

struct IComparable:IObject {
	virtual ~IComparable() {}
	virtual int compareTo(IComparable* obj) const;
};