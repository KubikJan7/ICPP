#include "objectTypes.h"

std::string Object::getString() const
{
	if (this->isType(FieldType::String))
		return ((StringObject*)this)->getValue();
	return "";
}

void Object::setString(std::string value)
{
	if (this->isType(FieldType::String))
		((StringObject*)this)->setValue(value);
}

int Object::getInt() const
{
	if (this->isType(FieldType::Integer))
		return ((IntObject*)this)->getValue();
	return NULL;
}

void Object::setInt(int value)
{
	if (this->isType(FieldType::Integer))
		((IntObject*)this)->setValue(value);
}

double Object::getDouble() const
{
	if (this->isType(FieldType::Double))
		return ((DoubleObject*)this)->getValue();
	return NULL;
}

void Object::setDouble(double value)
{
	if (this->isType(FieldType::Double))
		((DoubleObject*)this)->setValue(value);
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
	if (this->type == type)
		return true;
	else
		return false;
}
