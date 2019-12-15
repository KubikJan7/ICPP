#ifndef DB_H
#define DB_H
#include "platform.h"
#include <string>
#include "table.h"
#include <stdexcept>

// Databáze
class DLL_SPEC Db {

private:
	std::string databaseName;
	std::string* tableNames;
	int tableNamesLength;
	int tableCount;
	bool isTablePresent(std::string table);
	void enlargeTableNamesArray(int amount = 10);
public:
	Db(std::string databaseName, int tableNamesLength = 10);
	~Db();
	// Otevøe databázi
	static Db* open(std::string database);
	// Uzavøe databázi (dealokuje pamìové prostøedky)
	void close();

	// Vytvoøí novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otevøe existující tabulku
	Table* openTable(std::string name);
	// Otevøe tabulku (pokud neexistuje, vytvoøí automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);

	// Alokuje objekt „int“
	static Object* Int(int value);
	// Alokuje objekt „double“
	static Object* Double(double value);
	// Alokuje objekt „string“
	static Object* String(std::string value);
	// Alokuje objekt „field“
	static FieldObject* Field(std::string name, FieldType type);
};
// --------------------------------------------------------

#endif
