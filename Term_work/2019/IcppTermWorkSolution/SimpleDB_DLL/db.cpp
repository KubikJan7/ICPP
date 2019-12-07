#include<stdexcept>
#include "db.h"

Db::Db(int tablesLength)
{
	this->tableCount = 0;
	this->tablesLength = tablesLength;
	tables = new Table * [tablesLength];
}

Db::~Db()
{
	for (int i = 0; i < tableCount; i++)
	{
		delete tables[i];
	}

	delete[] tables;
}

Db* Db::open(std::string database)
{
	return nullptr;
}

void Db::close()
{
	Db::~Db();
}

Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields)
{
	if (name.compare("") == 0 || fieldsCount == 0 || fields == nullptr)
		throw std::invalid_argument("One of the given parameters is empty.");

	Table* t = new Table{name,fieldsCount};
	t->insert((Object**) fields);
	return t;
}

Table* Db::openTable(std::string name)
{
	if (name.compare("") == 0)
		throw std::invalid_argument("The given name parameter is empty.");

	for (int i = 0; i < tableCount; i++)
	{
		if (name.compare(tables[i]->getTableName()) == 0)
			return tables[i];
	}

	throw  std::invalid_argument("Table with the given name was not found!");
}

Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields)
{
	if (name.compare("") == 0)
		throw std::invalid_argument("The given name parameter is empty.");

	try {
		openTable(name);
	}
	catch (std::invalid_argument e)
	{
		createTable(name, fieldsCount, fields);
	}

	return nullptr;
}

Object* Db::Int(int value)
{
	return new IntObject{ value };
}

Object* Db::Double(double value)
{
	return new DoubleObject{ value };
}

Object* Db::String(std::string value)
{
	return new StringObject{ value };
}

FieldObject* Db::Field(std::string name, FieldType type)
{
	return new FieldObject{name, type};
}
