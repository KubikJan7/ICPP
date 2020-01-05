#ifndef PRVEK_VYRAZU_H
#define PRVEK_VYRAZU_H

#include <string>

struct PrvekVyrazu
{
public:
	~PrvekVyrazu() {}
	virtual std::string getTyp() const = 0;
};

#endif

