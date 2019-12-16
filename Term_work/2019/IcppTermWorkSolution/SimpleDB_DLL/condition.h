#ifndef CONDITION_H
#define CONDITION_H

#include "platform.h"
#include "interfaces.h"

class DLL_SPEC Condition : public ICondition {
public:
	virtual ~Condition();
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const override;
};

#endif