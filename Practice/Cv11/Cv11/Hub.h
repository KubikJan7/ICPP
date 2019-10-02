#include"AsitovyPrvek.h"
#include"Fronta.h"

struct Hub:ASitovyPrvek {
private:
	ASitovyPrvek** pripojenePrvky;
	int maximumPripojenychPrvku;
	Fronta<Zprava*> zpracovaneZpravy;

	virtual void ZpracujPrichoziZpravu(ZpravaPort zp);

public:
	Hub(int maximumPripojenychPrvku);
	virtual void Pripoj(ASitovyPrvek sitovyPrvek);
	virtual void Provadej();
};