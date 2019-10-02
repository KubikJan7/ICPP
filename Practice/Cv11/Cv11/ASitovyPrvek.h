#include"Zprava.h"
#include "Fronta.h"
#include"ZpravaPort.h"

class ASitovyPrvek {
protected:
	Fronta<ZpravaPort> prichoziZpravy;

	virtual void ZpracujPrichoziZpravu(ZpravaPort zp);

public:
	void VlozPrichoziZpravu(Zprava *zprava, ASitovyPrvek port);
	virtual void Provadej();
	virtual void Pripoj(ASitovyPrvek sitovyPrvek);
};