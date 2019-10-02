#include<string>
#include"ASitovyPrvek.h"
struct Uzel:ASitovyPrvek {
private:
	std::string adresa;
	ASitovyPrvek pripojenyPrvek;
	Fronta<Zprava*> odchoziZpravy;

	virtual void ZpracujPrichoziZpravu(ZpravaPort zp);

public:
	Uzel(std::string adresa);
	virtual void Pripoj(ASitovyPrvek sitovyPrvek);
	virtual void Provadej();
	void PripravZpravuKOdeslani(std::string cil, std::string obsah);


};