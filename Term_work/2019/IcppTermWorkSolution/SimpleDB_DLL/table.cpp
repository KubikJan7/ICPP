#include<stdexcept>
#include<fstream>
#include "table.h"
#include"simpleDbException.h"
#include <iostream>

using namespace std;
void Table::resizeDataArray()
{
	rowCount *= 2;
	Object*** newArr = new Object * *[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		newArr[i] = new Object * [fieldCount];
		if (rowCount <= numOfEntries)
			for (int j = 0; j < fieldCount; j++)
			{
				switch (data[i][j]->getDataType()) {
				case FieldType::Integer:
					newArr[i][j] = new IntObject();
					newArr[i][j]->setInt(data[i][j]->getInt());
					cout << newArr[i][j]->getInt();
					break;
				case FieldType::Double:
					newArr[i][j] = new DoubleObject();
					newArr[i][j]->setDouble(data[i][j]->getDouble());
					break;
				case FieldType::String:
					newArr[i][j] = new StringObject();
					newArr[i][j]->setString(data[i][j]->getString());
					cout << newArr[i][j]->getString();
					break;
				}
			}
	}

	for (int i = 0; i < rowCount / 2; i++)
	{
		for (int j = 0; j < fieldCount; j++)
		{
			delete data[i][j];
		}
		delete[] data[i];
	}
	delete[] data;

	data = newArr;
}
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

	if (numOfEntries >= rowCount)
		resizeDataArray();

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
	FieldType type;
	ofstream out("../SimpleDB_DLL/SimpleDB files/" + database + "_" + name + "_data" + ".dat");

	if (out.is_open()) {
		out << numOfEntries << endl;
		for (int i = 0; i < numOfEntries; i++)
		{
			//out.write((char*)&data[i], sizeof(data[i]));
			for (int j = 0; j < fieldCount; j++)
			{
				type = data[i][j]->getDataType();
				switch (type) {
				case FieldType::Integer:
					out << Object::fieldTypeToString(FieldType::Integer) << " ";
					out << data[i][j]->getInt() << "\t";
					break;
				case FieldType::Double:
					out << Object::fieldTypeToString(FieldType::Double) << " ";
					out << data[i][j]->getDouble() << "\t";
					break;
				case FieldType::String:
					out << Object::fieldTypeToString(FieldType::String) << " ";
					out << data[i][j]->getString() << "\t";
					break;
				}
			}
			out << endl;
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
