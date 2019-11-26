#ifndef I_POTRUBI_H
#define I_POTRUBI_H

struct APotrubniPrvek;
struct IPotrubi {
	virtual ~IPotrubi() {};
	virtual const APotrubniPrvek* DejPrvek(int x, int y) const = 0;
	virtual bool JePotrubiOk() const = 0;
};
#endif