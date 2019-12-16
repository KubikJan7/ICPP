#include "condition.h"

Condition::~Condition()
{
}

bool Condition::matches(int fieldCount, FieldObject** fields, Object** row) const
{
	return row[0]->getInt() > 2;
}
