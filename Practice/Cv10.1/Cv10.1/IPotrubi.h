#include "APotrubniPrvek.h"
struct IPotrubi {
	virtual ~IPotrubi() {

	};
	virtual const APotrubniPrvek* DejPrvek(int x, int y) const = 0;
	virtual bool JePotrubiOk() const = 0;
};