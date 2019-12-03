#include"Sit.h"

int Sit::idZpravy = 0;

int Sit::DejNoveId() {
	return idZpravy++;
}
void Sit::Pripoj(ASitovyPrvek* sitovyPrvek) {
	if (!sitovePrvky.Obsahuje(sitovyPrvek)) {
		sitovePrvky.Vloz(sitovyPrvek);
	}
}
void Sit::ProvadejVse() {
	sitovePrvky.ZpracujPrvky([](ASitovyPrvek* sp) { sp->Provadej(); });
}