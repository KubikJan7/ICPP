#include "Operator.h"

Operator::Operator(char oper)
{
	this->oper = oper;
}

char Operator::getOperator()
{
	return oper;
}

std::string Operator::getTyp() const
{
	return "operator";
}
