#ifndef HUB_H
#define HUB_H

#include "ASitovyPrvek.h"
#include "Fronta.h"

struct Hub : ASitovyPrvek
{

private:
	ASitovyPrvek** pripojenePrvky;
	int maximumPripojenychPrvku;
	Fronta<Zprava*> zpracovaneZpravy;
	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) override;

public:
	Hub(int maximumPripojenychPrvku);
	~Hub();
	virtual void Pripoj(ASitovyPrvek* sitovyPrvek) override;
	virtual void Provadej() override;
};

#endif

