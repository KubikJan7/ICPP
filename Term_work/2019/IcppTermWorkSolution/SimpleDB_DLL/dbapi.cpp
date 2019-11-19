#include "dbapi.h"
#include<string>
#include<iostream>

using namespace std;

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
	if (this->isType(FieldType::String))
		return ((StringObject*)this)->value;
}

void Object::setString(std::string value)
{
	if (this->isType(FieldType::String))
		((StringObject*)this)->value = value;
}

int Object::getInt() const
{
	if (this->isType(FieldType::Integer))
		return ((IntObject*)this)->value;
}

void Object::setInt(int value)
{
	if (this->isType(FieldType::Integer))
		((IntObject*)this)->value = value;
}

double Object::getDouble() const
{
	if (this->isType(FieldType::Double))
		return ((DoubleObject*)this)->value;
}

void Object::setDouble(double value)
{
	if (this->isType(FieldType::Double))
		((DoubleObject*)this)->value = value;
}

bool Object::isType(FieldType type) const
{
	if (this->getDataType() == type)
		return true;
	else
		return false;
}

bool FieldObject::isType(FieldType type) const
{
	if (typeid(this->type) == (typeid(type)))
		return true;
	else
		return false;
}
