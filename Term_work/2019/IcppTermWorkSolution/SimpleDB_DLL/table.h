#ifndef TABLE_H
#define TABLE_H

#include <functional>
#include "platform.h"
#include "objectTypes.h"
#include "interfaces.h"

// Tabulka
class DLL_SPEC Table {
private:
	std::string name;
	std::string database;
	FieldObject** fields;
	Object*** data;
	int rowCount;
	int fieldCount;
	int numOfEntries;
	// Add more rows to the object array
	void enlargeDataArray();
public:
	Table(std::string name, std::string database, int fieldCount, FieldObject** fields, int rowCount = 10);
	~Table();
	// Vloení nového øádku do tabulky (pole Object* (pro jednotlivé hodnoty sloupeèkù))
	void insert(Object** row);
	// Smazání vyrabného øádku z tabulky
	void remove(int rowid);

	// Select – vytvoøí iterátor k procházení tabulky
	IIterator* select();

	// Commit – pøenese zmìny z pamìti do datovıch souborù
	void commit();

	// Uzavøe tabulku (dealokuje pamìové prostøedky)
	void close();

	// Vrací poèet øádkù v tabulce
	int getRowCount() const;

	// Vrací pole FieldObject* popisující sloupeèky tabulky
	FieldObject** getFields() const;

	// Vrací poèet sloupeèkù
	int getFieldCount() const;

	std::string getTableName() const;

	// ============== Bonusové metody: ================
	// Select s podmínkou
	IIterator* select(ICondition* condition) { throw 0; }
	// Nalezení rowId s podmínkou
	int findRowId(ICondition* condition) { throw 0; }
	// Update – aktualizuje øádky vyhovující podmínce, aktualizaci provádí funkce „callback“
	// callback na vstupu obdrí data øádku a vrací data
	void update(ICondition* condition, std::function<void(Object**)> callback) { throw 0; }
};
#endif