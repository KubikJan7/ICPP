#ifndef OPERATOR_H
#define OPERATOR_H

#include "PrvekVyrazu.h"

struct Operator : PrvekVyrazu
{
private:
	char oper;
public:
	Operator(char oper);
	char getOperator();
	virtual std::string getTyp() const override;
};

#endif

