#ifndef HUB_H
#define HUB_H

#include"AsitovyPrvek.h"
#include"Fronta.h"

struct Hub:ASitovyPrvek {
private:
	ASitovyPrvek** pripojenePrvky;
	int maximumPripojenychPrvku;
	Fronta<Zprava*> zpracovaneZpravy;

	virtual void ZpracujPrichoziZpravu(ZpravaPort zp ) override;
public:
	~Hub();
	Hub(int maximumPripojenychPrvku);
	virtual void Pripoj(ASitovyPrvek* sitovyPrvek) override;
	virtual void Provadej() override;
};

#endif