#ifndef OBJECT_TYPES_H
#define OBJECT_TYPES_H

#include "platform.h"
#include <string>
#include "fieldType.h"

// Polymorfní datový objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhraní vyhovuje základním typùm int, double, string; pro typ „field“ je rozhraní rozšíøeno
class DLL_SPEC Object {
public:
	Object() {};
	virtual ~Object() {};

	// Gettery a settery podle typu
	// Jejich funkce je definována jen v pøípadì, že aktuální objekt je odpovídajícího typu
	// Automatické konverze v základním API nejsou vyžadovány

	virtual std::string getString() const;
	virtual void setString(std::string value);

	virtual int getInt() const;
	virtual void setInt(int value);

	virtual double getDouble() const;
	virtual void setDouble(double value);

	// Vrací true, pokud aktuální objekt pøedstavuje daný typ
	virtual bool isType(FieldType type) const;

	// Will return data type of the derived class
	virtual FieldType getDataType() const = 0;

	static std::string fieldTypeToString(FieldType type);
	static FieldType stringToFieldType(std::string typeName);
};


class DLL_SPEC IntObject : public Object {
private:
	int value;
public:
	IntObject() : value(0) {}
	IntObject(int v) : value(v) {}
	virtual FieldType getDataType() const { return FieldType::Integer; };

	void setValue(int value) { this->value = value; };
	int getValue() { return value; };
};


class DLL_SPEC DoubleObject : public Object {
private:
	double value;
public:
	DoubleObject() : value(0.0) {}
	DoubleObject(double v) : value(v) {}
	virtual FieldType getDataType() const { return FieldType::Double; };

	void setValue(double value) { this->value = value; };
	double getValue() { return value; };
};


class DLL_SPEC StringObject : public Object {
private:
	std::string value;
public:
	StringObject() : value("") {}
	StringObject(std::string v) : value(v) {}
	virtual FieldType getDataType() const { return FieldType::String; };

	void setValue(std::string value) { this->value = value; };
	std::string getValue() { return value; };
};


// Objekt popisující sloupeèek „field“
class DLL_SPEC FieldObject : public Object {
private:
	FieldType type;
	std::string name;
public:
	FieldObject() : type(FieldType::Integer), name("") {}
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}

	virtual bool isType(FieldType type) const override;
	virtual FieldType getDataType() const { return FieldType::Field; };

	// Název sloupeèku
	std::string getName() const { return name; }
	// Typ sloupeèku
	FieldType getType() const { return type; }
};

#endif
