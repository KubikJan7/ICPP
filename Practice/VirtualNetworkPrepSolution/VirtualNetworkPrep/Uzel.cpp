#include "Uzel.h"
#include <iostream>

using namespace std;
void Uzel::ZpracujPrichoziZpravu(ZpravaPort zp)
{
	if (adresa != zp.zprava->adrCil)
		return;

	cout << adresa << " RECV id: " << zp.zprava->id << " src: " << zp.zprava->adrZdroj << " msg: " << zp.zprava->obsah << endl;

	if (zp.zprava->obsah == "ping")
		PripravZpravuKOdeslani(zp.zprava->adrZdroj, "pong");
}

Uzel::Uzel(std::string adresa)
{
	this->adresa = adresa;
}

Uzel::~Uzel()
{
	delete pripojenyPrvek;
}

void Uzel::Pripoj(ASitovyPrvek* sitovyPrvek)
{
	pripojenyPrvek = sitovyPrvek;
}

void Uzel::Provadej()
{
	while (!odchoziZpravy.JePrazdna())
	{
		Zprava* z = odchoziZpravy.Odeber();
		pripojenyPrvek->VlozPrichoziZpravu(z, this);
	}

	while (!prichoziZpravy.JePrazdna())
	{
		ZpravaPort zp = prichoziZpravy.Odeber();
		ZpracujPrichoziZpravu(zp);
	}
}

void Uzel::PripravZpravuKOdeslani(std::string cil, std::string obsah)
{
	Zprava* z = new Zprava{ 0, adresa, cil, obsah };
	odchoziZpravy.Vloz(z);
}
