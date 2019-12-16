#ifndef ITERATOR_H
#define ITERATOR_H

#include "platform.h"
#include "interfaces.h"

class DLL_SPEC Iterator : public IIterator {
private:
	int position;
	int rowCount;
	int fieldCount;
	int numOfEntries;
	Object*** data;
	bool hasCondition;
public:
	Iterator(int rowCount, int fieldCount, int numOfEntries, Object*** data, bool hasCondition = false);
	virtual ~Iterator();
	virtual bool moveNext() override;
	virtual Object** getRow() override;
	virtual int getRowId() override;
	virtual void close() override;
};

#endif
