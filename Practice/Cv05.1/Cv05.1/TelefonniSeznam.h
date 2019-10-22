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
		std::string najdiTelefon(std::string jmeno)const;
		std::string najdiTelefon(int id)const;
		void smazSeznam()const;
	};
}
#endif