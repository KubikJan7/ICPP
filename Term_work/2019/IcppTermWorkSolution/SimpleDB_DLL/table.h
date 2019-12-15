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
	// Vlo�en� nov�ho ��dku do tabulky (pole Object* (pro jednotliv� hodnoty sloupe�k�))
	void insert(Object** row);
	// Smaz�n� vyrabn�ho ��dku z tabulky
	void remove(int rowid);

	// Select � vytvo�� iter�tor k proch�zen� tabulky
	IIterator* select();

	// Commit � p�enese zm�ny z pam�ti do datov�ch soubor�
	void commit();

	// Uzav�e tabulku (dealokuje pam�ov� prost�edky)
	void close();

	// Vrac� po�et ��dk� v tabulce
	int getRowCount() const;

	// Vrac� pole FieldObject* popisuj�c� sloupe�ky tabulky
	FieldObject** getFields() const;

	// Vrac� po�et sloupe�k�
	int getFieldCount() const;

	std::string getTableName() const;

	// ============== Bonusov� metody: ================
	// Select s podm�nkou
	IIterator* select(ICondition* condition) { throw 0; }
	// Nalezen� rowId s podm�nkou
	int findRowId(ICondition* condition) { throw 0; }
	// Update � aktualizuje ��dky vyhovuj�c� podm�nce, aktualizaci prov�d� funkce �callback�
	// callback na vstupu obdr�� data ��dku a vrac� data
	void update(ICondition* condition, std::function<void(Object**)> callback) { throw 0; }
};
#endif