#ifndef DB_H
#define DB_H
#include "platform.h"
#include <string>
#include "table.h"

// Datab�ze
class DLL_SPEC Db {
public:
	// Otev�e datab�zi
	static Db* open(std::string database);
	// Uzav�e datab�zi (dealokuje pam�ov� prost�edky)
	void close();

	// Vytvo�� novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otev�e existuj�c� tabulku
	Table* openTable(std::string name);
	// Otev�e tabulku (pokud neexistuje, vytvo�� automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);

	// Alokuje objekt �int�
	static Object* Int(int value);
	// Alokuje objekt �double�
	static Object* Double(double value);
	// Alokuje objekt �string�
	static Object* String(std::string value);
	// Alokuje objekt �field�
	static FieldObject* Field(std::string name, FieldType type);
};
// --------------------------------------------------------

#endif
