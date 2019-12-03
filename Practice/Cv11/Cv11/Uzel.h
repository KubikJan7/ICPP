#ifndef UZEL_H
#define UZEL_H

#include<string>
#include"ASitovyPrvek.h"
struct Uzel:ASitovyPrvek {
private:
	std::string adresa;
	ASitovyPrvek* pripojenyPrvek;
	Fronta<Zprava*> odchoziZpravy;

	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) override;

public:
	~Uzel();
	Uzel(std::string adresa);
	virtual void Pripoj(ASitovyPrvek* sitovyPrvek) override;
	virtual void Provadej() override;
	void PripravZpravuKOdeslani(std::string cil, std::string obsah);


};

#endif