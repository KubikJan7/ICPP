#pragma once
#include "PrvekVyrazu.h"
class Operator :
	public PrvekVyrazu
{
private:
	char oper;

public:
	Operator(char o);

	char getOperator() const;

	virtual bool jeOperator() const override;
	virtual bool jeHodnota() const override;

};

