#ifndef OPERATOR_H
#define OPERATOR_H

#include "PrvekVyrazu.h"

struct Operator : PrvekVyrazu
{
private:
	char oper;
public:
	Operator(char oper) : oper(oper) {}
	~Operator() {}
	virtual std::string getType() override { return "Operator"; }

	char getOperator() { return oper; }
};

#endif