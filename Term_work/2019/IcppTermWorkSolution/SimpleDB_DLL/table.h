#ifndef TABLE_H
#define TABLE_H

#include <functional>
#include "platform.h"
#include "objectTypes.h"
#include "interfaces.h"

// Tabulka
class DLL_SPEC Table {
private:
	Object*** table;
	int rowCount;
	int fieldCount;
	int numberOfEntries;
public:
	Table(int fieldCount, int rowCount = 10);
	~Table();
	// Vloení nového øádku do tabulky (pole Object* (pro jednotlivé hodnoty sloupeèkù))
	void insert(Object** row);
	// Smazání vyrabného øádku z tabulky
	void remove(int rowid);

	// Select – vytvoøí iterátor k procházení tabulky
	Iterator* select();

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


	// ============== Bonusové metody: ================
		// Select s podmínkou
	Iterator* select(Condition* condition) { throw 0; }
	// Nalezení rowId s podmínkou
	int findRowId(Condition* condition) { throw 0; }
	// Update – aktualizuje øádky vyhovující podmínce, aktualizaci provádí funkce „callback“
	// callback na vstupu obdrí data øádku a vrací data
	void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }
};
#endif