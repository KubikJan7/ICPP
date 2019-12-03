#include"Uzel.h"

Uzel::~Uzel()
{

}

Uzel::Uzel(std::string adresa) {
	this->adresa = adresa;
}

void Uzel::ZpracujPrichoziZpravu(ZpravaPort zp) {
	if (zp.zprava->adrCil != adresa)
		return;

	cout << adresa << "RECV id:" << zp.id ...;

	if (zp.zprava->obsah == "ping") {
		PripravZpravuKOdeslani(zp.zprava->adrZdroj, "pong");
	}
}
void Uzel::Pripoj(ASitovyPrvek* sitovyPrvek) {

}
void Uzel::Provadej() {
	while (!odchoziZpravy.JePrazdna()) {
		Zprava* zpravaKOdeslani = odchoziZpravy.Odeber();

		pripojenyPrvek->VlozPrichoziZpravu(zpravaKOdeslani, this);
	}

	while (!prichoziZpravy.JePrazdna()) {
		ZpravaPort prichoziZprava = prichoziZpravy.Odeber();
		ZpracujPrichoziZpravu(prichoziZprava);
	}
}
void Uzel::PripravZpravuKOdeslani(std::string cil, std::string obsah) {
	Zprava* novaZprava = new Zprava{ 0, adresa, cil, obsah };

	odchoziZpravy.Vloz(novaZprava);
}
