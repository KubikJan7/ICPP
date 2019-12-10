#include<fstream>
#include<iostream>
#include "db.h"
#include "simpleDbException.h"

using namespace std;

std::string Db::fieldTypeToString(FieldType type)
{
	switch (type) {
	case FieldType::Integer:
		return "INT";
	case FieldType::Double:
		return "DOUBLE";
	case FieldType::String:
		return "STRING";
	default:
		throw WrongInputException("Given type is not supported by the database!");
	}
}

FieldType Db::stringToFieldType(std::string typeName)
{
	if (typeName.compare("INT") == 0)
		return FieldType::Integer;
	if (typeName.compare("DOUBLE") == 0)
		return FieldType::Double;
	if (typeName.compare("STRING") == 0)
		return FieldType::String;
	else
		throw WrongInputException("Given type name does not match any of the database data types!");

}

bool Db::isTablePresent(std::string table)
{
	for (int i = 0; i < tableCount; i++)
	{
		if (table.compare(tableNames[i]) == 0)
			return true;
	}
	return false;
}

Db::Db(string databaseName, int tablesLength)
{
	this->databaseName = databaseName;
	tableCount = 0;
	this->tableNamesLength = tablesLength;
	tableNames = new string[tablesLength];
}

Db::~Db()
{
	delete[] tableNames;
}

Db* Db::open(std::string database)
{
	Db* db = new Db{ database };
	ifstream in{};
	in.open("../SimpleDB_DLL/SimpleDB files/" + database + ".txt");
	if (!in.is_open()) //Check if the file does exist
		return db; //Initialize new database
	else
	{
		string s;
		while (in >> s) {
			if (db->tableCount == db->tableNamesLength)
			{
				//TODO: allocate a bigger array
			}
			db->tableNames[db->tableCount] = s;
			db->tableCount++;
		}
		in.close();
	}
	return db;
}

void Db::close()
{
	Db::~Db();
}

Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields)
{
	if (!isTablePresent(name)) {
		if (name.compare("") == 0 || fieldsCount == 0 || fields == nullptr)
			throw std::invalid_argument("One of the given parameters is empty.");

		Table* t = new Table{ name,fieldsCount };
		t->insert((Object**)fields);

		tableNames[tableCount] = name;
		tableCount++;

		ofstream out{};

		//Create file with list with all available tables
		out.open("../SimpleDB_DLL/SimpleDB files/" + databaseName + "_table_list" + ".txt");
		if (out.is_open())
			for (int i = 0; i < tableCount; i++)
			{
				out << tableNames[i] << endl;
			}
		out.close();

		//Create schema of the new table
		out.open("../SimpleDB_DLL/SimpleDB files/" + databaseName + "_" + name + "_schema" + ".txt");
		if (out.is_open())
		{
			string fieldType;
			out << "table " << name << endl;
			for (int i = 0; i < fieldsCount; i++)
			{
				fieldType = fieldTypeToString(fields[i]->getType());
				out << fields[i]->getName() << " " << fieldType << endl;
			}
		}
		out.close();
		return t;
	}
	throw InvalidOperationException("Table with given name already exists!");
}

Table* Db::openTable(std::string name)
{
	bool tableWasFound = false;
	if (name.compare("") == 0)
		throw WrongInputException("The given name parameter is empty.");

	if (isTablePresent(name))
	{
		ifstream in("../SimpleDB_DLL/SimpleDB files/" + databaseName + "_" + name + "_schema" + ".txt");
	}
	else
		throw  WrongInputException("Table with the given name was not found!");
}

Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields)
{
	if (name.compare("") == 0)
		throw WrongInputException("The given name parameter is empty.");

	if (isTablePresent(name))
		return openTable(name);
	else
		return createTable(name, fieldsCount, fields);
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
	return new FieldObject{ name, type };
}
