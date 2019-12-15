#include<fstream>
#include<iostream>
#include "db.h"
#include "simpleDbException.h"

using namespace std;

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
	in.open("../SimpleDB_DLL/SimpleDB files/" + database + "_table_list" + ".txt");
	if (!in.is_open()) //Check if the file does exist
		return db; //Return a new database
	else
	{
		string s;
		while (in >> s) {
			if (db->tableCount >= db->tableNamesLength)
			{
				db->enlargeTableNamesArray();
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
	databaseName = "";
	tableNamesLength = tableCount = 0;
}

Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields)
{
	if (!isTablePresent(name)) {
		if (name.compare("") == 0 || fieldsCount == 0 || fields == nullptr)
			throw std::invalid_argument("One of the given parameters is empty.");

		Table* t = new Table{ name,databaseName ,fieldsCount, fields };

		if (tableCount >= tableNamesLength)
		{
			enlargeTableNamesArray();
		}

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
			out << name << "\t[ " << fieldsCount << " ]" << endl;
			out << "==============" << endl;
			for (int i = 0; i < fieldsCount; i++)
			{
				fieldType = Object::fieldTypeToString(fields[i]->getType());
				out << fields[i]->getName() << "\t" << fieldType << endl;
			}
		}
		out.close();
		return t;
	}
	throw InvalidOperationException("Table with name: " + name + " already exists!");
}

Table* Db::openTable(std::string name)
{
	if (name.compare("") == 0)
		throw WrongInputException("The given name parameter is empty.");

	if (isTablePresent(name))
	{
		int fieldsCount;
		FieldObject** fields;
		string fieldName, fieldType;
		Table* t;

		// load table scheme
		ifstream in("../SimpleDB_DLL/SimpleDB files/" + databaseName + "_" + name + "_schema" + ".txt");
		if (in.is_open()) {
			in >> fieldName >> fieldName >> fieldsCount >> fieldName >> fieldName; // variable name is here used for omitting extra strings
			fields = new FieldObject * [fieldsCount];

			for (int i = 0; i < fieldsCount; i++)
			{
				in >> fieldName >> fieldType;
				fields[i] = new FieldObject{ fieldName,Object::stringToFieldType(fieldType) };
			}
			t = new Table{ name, databaseName, fieldsCount, fields };

			in.close();
		}
		else
			throw  LoadFileException("Something went wrong, table: " + name + " couldn't be loaded.");

		// load table data
		in.open("../SimpleDB_DLL/SimpleDB files/" + databaseName + "_" + name + "_data" + ".dat");
		if (in.is_open()) {
			int numOfEntries = 0;
			string typeName;
			int intVal;
			double doubleVal;
			string stringVal;
			in >> numOfEntries;
			for (int i = 0; i < numOfEntries; i++)
			{
				Object** row = new Object * [fieldsCount];
				for (int j = 0; j < fieldsCount; j++)
				{
					in >> typeName;
					switch (Object::stringToFieldType(typeName)) {
					case FieldType::Integer:
						in >> intVal;
						row[j] = new IntObject();
						row[j]->setInt(intVal);
						break;
					case FieldType::Double:
						in >> doubleVal;
						row[j] = new DoubleObject();
						row[j]->setDouble(doubleVal);
						break;
					case FieldType::String:
						in >> stringVal;
						row[j] = new StringObject();
						row[j]->setString(stringVal);
						break;
					}
				}
				t->insert(row);
			}
		}
		return t;

	}
	else
		throw  InvalidOperationException("Table with the name: " + name + " does not exist!");
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



bool Db::isTablePresent(std::string table)
{
	for (int i = 0; i < tableCount; i++)
	{
		if (table.compare(tableNames[i]) == 0)
			return true;
	}
	return false;
}

void Db::enlargeTableNamesArray(int amount)
{
	tableNamesLength += amount;
	string* newArr = new string[tableNamesLength];

	for (int i = 0; i < tableCount; i++)
	{
		newArr[i] = tableNames[i];
	}

	delete[]tableNames;

	tableNames = newArr;
}
