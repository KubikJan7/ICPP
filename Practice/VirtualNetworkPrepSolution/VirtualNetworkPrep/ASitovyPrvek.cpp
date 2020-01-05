#include "ASitovyPrvek.h"

void ASitovyPrvek::VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* port)
{
	ZpravaPort zp{zprava, port};
	prichoziZpravy.Vloz(zp);
}
