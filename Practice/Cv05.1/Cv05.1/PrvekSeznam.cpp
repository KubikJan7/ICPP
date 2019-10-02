#include <string>
#include "TelefonniSeznam.h"
#include "PrvekSeznamu.h"
#include "Osoba.h"


using namespace Entity;
using namespace std;
using namespace Model;

TelefonniSeznam sez;

void PrvekSeznamu::pridejOsobu(Entity::Osoba o) {
	PrvekSeznamu& p = PrvekSeznamu{o.id, o.jmeno, o.telefon};
	if (_zacatek == nullptr) {
		_zacatek = p;
	}
}
string PrvekSeznamu::najdiTelefon(string jmeno)const {

}
string PrvekSeznamu::najdiTelefon(int id)const {

}

PrvekSeznamu::PrvekSeznamu(int id, string jmeno, string telefon) {
Osoba:id = id;
Osoba:jmeno = jmeno;
Osoba:telefon = telefon;
}