#ifndef OPERATOR_H
#define OPERATOR_H
#include"prvekVyrazu.h"
struct Operator:PrvekVyrazu
{
private:
	char oper;
public:
	Operator();
	Operator(char oper);
	virtual ~Operator();
	virtual bool jeOperator()const;
	virtual bool jeHodnota()const;
	char getOperator();
};
#endif

