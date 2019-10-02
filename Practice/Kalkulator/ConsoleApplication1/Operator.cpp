#include "stdafx.h"
#include "Operator.h"

Operator::Operator(char o) : oper(o) {
}

char Operator::getOperator() const { return oper; }

bool Operator::jeOperator() const { return true; }
bool Operator::jeHodnota() const { return false; }
