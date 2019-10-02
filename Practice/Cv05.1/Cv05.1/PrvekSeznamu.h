#include <string>
#include "Osoba.h"
using namespace std;

struct PrvekSeznamu {
	PrvekSeznamu* _zacatek;

	PrvekSeznamu(int id, string jmeno, string telefon);

	void pridejOsobu(Entity::Osoba o);
	string najdiTelefon(string jmeno)const;
	string najdiTelefon(int id)const;
};