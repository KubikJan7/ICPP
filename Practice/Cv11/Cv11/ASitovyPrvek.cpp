#include"ASitovyPrvek.h"

ASitovyPrvek::~ASitovyPrvek()
{
}

void ASitovyPrvek::VlozPrichoziZpravu(Zprava *zprava, ASitovyPrvek* port) {
	ZpravaPort zpravaPort{zprava,port};
	prichoziZpravy.Vloz(zpravaPort);
}