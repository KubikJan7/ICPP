#ifndef INTERFACES_H
#define INTERFACES_H
#include "platform.h"
#include "objectTypes.h"

// Rozhraní definující podmínku – pouze pro bonusové metody
class DLL_SPEC ICondition {
public:
	virtual ~ICondition() { };
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------

// Rozhraní iterátoru (select)
class DLL_SPEC IIterator {
public:
	virtual ~IIterator() { };

	// Posun na další øádek (vrací true, pokud je iterátor platnı; logika podle Java Iterator)
	virtual bool moveNext() = 0;
	// Vrací pole Object* obsahující data øádku
	virtual Object** getRow() = 0;
	// Vrací interní rowId aktuálního øádku
	virtual int getRowId() = 0;
	// Uzavøe iterátor (dealokuje pamìové prostøedky)
	virtual void close() = 0;
};

#endif