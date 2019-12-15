#include "iterator.h"
#include <iostream>
Iterator::Iterator(int rowCount, int fieldCount, int numOfEntries, Object*** data)
{
	position = -1;
	this->rowCount = rowCount;
	this->fieldCount = fieldCount;
	this->numOfEntries = numOfEntries;
	this->data = data;
}

Iterator::~Iterator()
{
	data = nullptr;
}

bool Iterator::moveNext()
{
	if (++position < numOfEntries) {
		return true;
	}
	else
		return false;
}

Object** Iterator::getRow()
{
	return data[position];
}

int Iterator::getRowId()
{
	return position;
}

void Iterator::close()
{
	Iterator::~Iterator();
	rowCount = fieldCount = numOfEntries = position = 0;
}
