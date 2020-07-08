#include "ASitovyPrvek.h"

void ASitovyPrvek::VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* port)
{
	prichoziZpravy.Vloz(ZpravaPort{ zprava,port });
}
