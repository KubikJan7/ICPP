#ifndef INTERFACES_H
#define INTERFACES_H
#include "platform.h"
#include "objectTypes.h"

// Rozhran� definuj�c� podm�nku � pouze pro bonusov� metody
class DLL_SPEC ICondition {
public:
	virtual ~ICondition() { };
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------

// Rozhran� iter�toru (select)
class DLL_SPEC IIterator {
public:
	virtual ~IIterator() { };

	// Posun na dal�� ��dek (vrac� true, pokud je iter�tor platn�; logika podle Java Iterator)
	virtual bool moveNext() = 0;
	// Vrac� pole Object* obsahuj�c� data ��dku
	virtual Object** getRow() = 0;
	// Vrac� intern� rowId aktu�ln�ho ��dku
	virtual int getRowId() = 0;
	// Uzav�e iter�tor (dealokuje pam�ov� prost�edky)
	virtual void close() = 0;
};

#endif