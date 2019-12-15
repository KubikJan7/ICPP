#include "iterator.h"

Iterator::Iterator(int rowCount, int fieldCount, int numOfEntries, Object*** data)
{
	position = 0;
	this->rowCount = rowCount;
	this->fieldCount = fieldCount;
	this->numOfEntries = numOfEntries;
	this->data = data;
}

Iterator::~Iterator()
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < numOfEntries; j++)
		{
			delete data[i][j];
		}
		delete[] data[i];
	}
	delete[] data;
}

bool Iterator::moveNext()
{
	if (++position < rowCount * fieldCount)
		return true;
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
}
