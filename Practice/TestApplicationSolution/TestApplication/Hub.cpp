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
