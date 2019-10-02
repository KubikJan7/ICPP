#include"Fronta.h"
#include"ASitovyPrvek.h"
struct Sit {
private:
	int idZpravy;
	Fronta<ASitovyPrvek*> sitovePrvky;

public:
	int DejNoveId();
	void Pripoj(ASitovyPrvek sitovyPrvek);
	void ProvadejVse();
};