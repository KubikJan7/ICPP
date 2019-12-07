#include "iterator.h"

Iterator::~Iterator()
{
}

bool Iterator::moveNext()
{
	return false;
}

Object** Iterator::getRow()
{
	return nullptr;
}

int Iterator::getRowId()
{
	return 0;
}

void Iterator::close()
{
}
