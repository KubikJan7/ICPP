#include<stdexcept>
#include<fstream>
#include "table.h"
#include"simpleDbException.h"
#include <iostream>

using namespace std;
Table::Table(string name, string database, int fieldCount, FieldObject** fields, int rowCount)
{
	numOfEntries = 0;
	this->name = name;
	this->database = database;
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

	data[numOfEntries] = row;
	numOfEntries++;
}

void Table::remove(int rowid)
{
	if (rowid > numOfEntries)
		throw std::out_of_range{ "Given id is bigger than the number of entries stored in the table." };

	for (int i = rowid; i < numOfEntries - 1; i++)
	{
		data[i] = data[i + 1];
	}
	data[numOfEntries - 1] = nullptr;
}

IIterator* Table::select()
{
	return nullptr;
}

void Table::commit()
{
	ofstream out("../SimpleDB_DLL/SimpleDB files/" + database + "_" + name + "_data" + ".dat", ios_base::binary);

	if (out.is_open()) {
		out.write((char*)&numOfEntries, sizeof(numOfEntries));
		for (int i = 0; i < numOfEntries; i++)
		{
			//out.write((char*)&data[i], sizeof(data[i]));
			for (int j = 0; j < fieldCount; j++)
			{
				out.write((char*)&data[i][j], sizeof(data[i][j]));
			}
		}
		out.close();
	}
	else
		throw  LoadFileException("Something went wrong, data of table: " + name + " couldn't be saved.");

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
