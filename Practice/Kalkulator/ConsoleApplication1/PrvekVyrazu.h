#pragma once
class PrvekVyrazu
{
public:
	PrvekVyrazu();
	virtual ~PrvekVyrazu();

	virtual bool jeOperator() const = 0;
	virtual bool jeHodnota() const = 0;
};

