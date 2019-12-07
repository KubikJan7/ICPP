#ifndef ITERATOR_H
#define ITERATOR_H

#include "platform.h"
#include "interfaces.h"
#include "objectTypes.h"

class DLL_SPEC Iterator : public IIterator {
public:
	virtual ~Iterator();
	virtual bool moveNext() override;
	virtual Object** getRow() override;
	virtual int getRowId() override;
	virtual void close() override;
};

#endif
