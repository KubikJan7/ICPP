#include "pch.h"
#include "operator.h"


Operator::Operator()
{
}
Operator::Operator(char oper) {
	this->oper = oper;
}

Operator::~Operator()
{
}
bool Operator::jeOperator()const {
	return true;
}
bool Operator::jeHodnota()const {
	return false;
}
char Operator::getOperator() {
	return oper;
}
