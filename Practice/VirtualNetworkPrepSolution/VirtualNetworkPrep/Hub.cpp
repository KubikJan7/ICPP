#include "Hub.h"

void Hub::ZpracujPrichoziZpravu(ZpravaPort zp)
{
	if (zpracovaneZpravy.Obsahuje(zp.zprava))
		return;

	for (int i = 0; i < maximumPripojenychPrvku; i++)
	{
		if (pripojenePrvky[i] == nullptr)
			break;

		if (zp.port != pripojenePrvky[i])
			pripojenePrvky[i]->VlozPrichoziZpravu(zp.zprava, this);
	}
	zpracovaneZpravy.Vloz(zp.zprava);
}

Hub::Hub(int maximumPripojenychPrvku)
{
	this->maximumPripojenychPrvku = maximumPripojenychPrvku;
	pripojenePrvky = new ASitovyPrvek * [maximumPripojenychPrvku];
	for (int i = 0; i < maximumPripojenychPrvku; i++)
	{
		pripojenePrvky[i] = nullptr;
	}
	zpracovaneZpravy = {};
}

Hub::~Hub()
{
	for (int i = 0; i < maximumPripojenychPrvku; i++)
	{
		delete pripojenePrvky[i];
	}
	delete[] pripojenePrvky;
}

void Hub::Pripoj(ASitovyPrvek* sitovyPrvek)
{
	for (int i = 0; i < maximumPripojenychPrvku; i++)
	{
		if (pripojenePrvky[i] == nullptr) {
			pripojenePrvky[i] = sitovyPrvek;
			return;
		}
	}
}

void Hub::Provadej()
{
	while (!prichoziZpravy.JePrazdna()) {
		ZpravaPort zp = prichoziZpravy.Odeber();
		ZpracujPrichoziZpravu(zp);
	}
}
