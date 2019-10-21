#include "dbapi.h"
#include<string>
#include<iostream>

using namespace std;

Db* Db::open(std::string database)
{
	cout << "sfdfsf" << endl;
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

Iterator::~Iterator()
{
}

void Table::insert(Object** row)
{
}

void Table::remove(int rowid)
{
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
	return 0;
}

FieldObject** Table::getFields() const
{
	return nullptr;
}

int Table::getFieldCount() const
{
	return 0;
}

Object::Object()
{
}

Object::~Object()
{
}

std::string Object::getString() const
{
	return std::string();
}

void Object::setString(std::string value)
{
}

int Object::getInt() const
{
	return 0;
}

void Object::setInt(int value)
{
}

double Object::getDouble() const
{
	return 0.0;
}

void Object::setDouble(double value)
{
}

bool Object::isType(FieldType type) const
{
	return false;
}

bool FieldObject::isType(FieldType type) const
{
	return false;
}
