#ifndef PRVEK_VYRAZU_H
#define PRVEK_VYRAZU_H

#include <string>

struct PrvekVyrazu
{
	virtual ~PrvekVyrazu() {}
	virtual std::string getType() = 0;
};

#endif
