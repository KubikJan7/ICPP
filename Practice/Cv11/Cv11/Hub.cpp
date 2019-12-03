#include"Hub.h"

Hub::~Hub()
{
	for (int i = 0; i < maximumPripojenychPrvku; i++)
	{
		delete[] pripojenePrvky;
	}
}

Hub::Hub(int maximumPripojenychPrvku) {
	this->maximumPripojenychPrvku = maximumPripojenychPrvku;
	this->pripojenePrvky = new ASitovyPrvek * [maximumPripojenychPrvku];
	for (int i = 0; i < maximumPripojenychPrvku; i++)
	{
		pripojenePrvky[i] = nullptr;
	}
	zpracovaneZpravy = {};
}

void Hub::ZpracujPrichoziZpravu(ZpravaPort zp) {
	if (zpracovaneZpravy.Obsahuje(zp.zprava)) 
		return;
	for (int i = 0; i < maximumPripojenychPrvku; i++)
	{
		if (pripojenePrvky[i] != nullptr) {
			if (pripojenePrvky[i] != zp.port) {
				pripojenePrvky[i]->VlozPrichoziZpravu(zp.zprava, this);
			}
	
		}
	}
	zpracovaneZpravy.Vloz(zp.zprava);
}

void Hub::Pripoj(ASitovyPrvek* sitovyPrvek) {
	for (int i = 0; i < maximumPripojenychPrvku; i++)
	{
		if (pripojenePrvky[i] == nullptr) {
			pripojenePrvky[i] = sitovyPrvek;
			break;
		}
	}
}
void Hub::Provadej() {
	while (!prichoziZpravy.JePrazdna()) {
		ZpravaPort zp = prichoziZpravy.Odeber();

		ZpracujPrichoziZpravu(zp);
	}
}


