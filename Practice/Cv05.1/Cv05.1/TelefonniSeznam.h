#ifndef TELEFONNI_SEZNAM_H
#define TELEFONNI_SEZNAM_H

#include"Osoba.h"
namespace Model {
	struct TelefonniSeznam {
		struct PrvekSeznamu {
			PrvekSeznamu* dalsi;
			Entity::Osoba data;
			PrvekSeznamu() : dalsi(nullptr), data() {}
		};

	private:
		PrvekSeznamu* _zacatek;
		

	public:
		TelefonniSeznam() : _zacatek(nullptr) {}
		void pridejOsobu(Entity::Osoba o);
		string najdiTelefon(string jmeno)const;
		string najdiTelefon(int id)const;
		Entity::Osoba odeberOsobu(string jmeno);
		Entity::Osoba odeberOsobu(int id);
	};
}
#endif