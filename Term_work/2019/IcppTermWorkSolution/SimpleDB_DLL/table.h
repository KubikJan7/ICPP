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
	// Vlo�en� nov�ho ��dku do tabulky (pole Object* (pro jednotliv� hodnoty sloupe�k�))
	void insert(Object** row);
	// Smaz�n� vyrabn�ho ��dku z tabulky
	void remove(int rowid);

	// Select � vytvo�� iter�tor k proch�zen� tabulky
	Iterator* select();

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


	// ============== Bonusov� metody: ================
		// Select s podm�nkou
	Iterator* select(Condition* condition) { throw 0; }
	// Nalezen� rowId s podm�nkou
	int findRowId(Condition* condition) { throw 0; }
	// Update � aktualizuje ��dky vyhovuj�c� podm�nce, aktualizaci prov�d� funkce �callback�
	// callback na vstupu obdr�� data ��dku a vrac� data
	void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }
};
#endif