#ifndef ASITOVY_PRVEK_H
#define ASITOVY_PRVEK_H

#include"Fronta.h"
#include"ZpravaPort.h"

struct ASitovyPrvek
{
protected:
	Fronta<ZpravaPort> prichoziZpravy;
	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) = 0;

public:
	virtual ~ASitovyPrvek() {}
	void VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* port);
	virtual void Provadej() = 0;
	virtual void Pripoj(ASitovyPrvek* sitovyPrvek) = 0;
};

#endif

