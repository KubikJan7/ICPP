#include<stdexcept>
#include "table.h"

Table::Table(std::string name, int fieldCount, FieldObject** fields, int rowCount)
{
	numberOfEntries = 0;
	this->name = name;
	this->rowCount = rowCount;
	this->fieldCount = fieldCount;
	this->fields = fields;

	data = new Object * *[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		data[i] = new Object * [fieldCount];
	}
}

Table::~Table()
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < fieldCount; j++)
		{
			delete data[i][j];
		}
		delete[] data[i];
	}
	delete[] data;
}

void Table::insert(Object** row)
{
	if (row == nullptr)
		throw std::invalid_argument{ "Given row is empty." };

	data[numberOfEntries] = row;
	numberOfEntries++;
}

void Table::remove(int rowid)
{
	if (rowid > numberOfEntries)
		throw std::out_of_range{ "Given id is bigger than the number of entries stored in the table." };

	for (int i = rowid; i < numberOfEntries - 1; i++)
	{
		data[i] = data[i + 1];
	}
	data[numberOfEntries - 1] = nullptr;
}

IIterator* Table::select()
{
	return nullptr;
}

void Table::commit()
{
}

void Table::close()
{
	Table::~Table();
}

int Table::getRowCount() const
{
	return rowCount;
}

FieldObject** Table::getFields() const
{
	return fields;
}

int Table::getFieldCount() const
{
	return fieldCount;
}

std::string Table::getTableName() const
{
	return name;
}
