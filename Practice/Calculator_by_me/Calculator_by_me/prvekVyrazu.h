#ifndef PRVEKVYRAZU_H
#define PRVEKVYRAZU_H
struct PrvekVyrazu {
	PrvekVyrazu(){}
	virtual ~PrvekVyrazu(){}
	virtual bool jeOperator()const = 0;
	virtual bool jeHodnota()const = 0;
};
#endif