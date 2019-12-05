#include "db.h"

Db* Db::open(std::string database)
{
	return nullptr;
}

void Db::close()
{
}

Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields)
{
	return nullptr;
}

Table* Db::openTable(std::string name)
{
	return nullptr;
}

Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields)
{
	return nullptr;
}

Object* Db::Int(int value)
{
	return nullptr;
}

Object* Db::Double(double value)
{
	return nullptr;
}

Object* Db::String(std::string value)
{
	return nullptr;
}

FieldObject* Db::Field(std::string name, FieldType type)
{
	return nullptr;
}
