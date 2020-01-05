#ifndef UZEL_H
#define UZEL_H

#include "ASitovyPrvek.h"
#include "Fronta.h"
#include<string>

struct Uzel : ASitovyPrvek
{

private:
	std::string adresa;
	ASitovyPrvek* pripojenyPrvek;
	Fronta<Zprava*> odchoziZpravy;
	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) override;

public:
	Uzel(std::string adresa);
	~Uzel();
	virtual void Pripoj(ASitovyPrvek* sitovyPrvek) override;
	virtual void Provadej() override;
	void PripravZpravuKOdeslani(std::string cil, std::string obsah);
};

#endif

