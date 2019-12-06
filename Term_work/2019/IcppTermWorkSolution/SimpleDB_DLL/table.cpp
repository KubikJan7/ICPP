#include<stdexcept>
#include "table.h"

Table::Table(int fieldCount, int rowCount)
{
	numberOfEntries = 0;
	this->rowCount = rowCount;
	this->fieldCount = fieldCount;

	table = new Object * *[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		table[i] = new Object * [fieldCount];
	}
}

Table::~Table()
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < fieldCount; j++)
		{
			delete table[i][j];
		}
		delete[] table[i];
	}
	delete[] table;
}

void Table::insert(Object** row)
{
	if (row == nullptr)
		throw std::invalid_argument{"Given row is empty."};

	table[numberOfEntries] = row;
	numberOfEntries++;
}

void Table::remove(int rowid)
{
	if (rowid > numberOfEntries)
		throw std::out_of_range{"Given id is bigger than the number of entries stored in the table."};

	for (int i = 0; i < rowCount; i++)
	{

	}
}

Iterator* Table::select()
{
	return nullptr;
}

void Table::commit()
{
}

void Table::close()
{
}

int Table::getRowCount() const
{
	return rowCount;
}

FieldObject** Table::getFields() const
{
	return nullptr;
}

int Table::getFieldCount() const
{
	return fieldCount;
}
