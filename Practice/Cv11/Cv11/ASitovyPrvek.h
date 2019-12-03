#ifndef A_SITOVY_PRVEK_H
#define A_SITOVY_PRVEK_H

#include"Zprava.h"
#include "Fronta.h"
#include"ZpravaPort.h"

struct ASitovyPrvek {
protected:
	Fronta<ZpravaPort> prichoziZpravy;

	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) = 0;

public:
	~ASitovyPrvek();
	void VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* port);
	virtual void Provadej()  = 0;
	virtual void Pripoj(ASitovyPrvek* sitovyPrvek) = 0;
};

#endif