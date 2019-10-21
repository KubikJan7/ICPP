#ifndef TELEFONNI_SEZNAM_H
#define TELEFONNI_SEZNAM_H

#include"Osoba.h"
namespace Model {
	struct TelefonniSeznam {
		class PrvekSeznamu {
			PrvekSeznamu* dalsi;
			Entity::Osoba data;
		public:
			PrvekSeznamu() : dalsi(nullptr), data() {}
		};

	private:
		PrvekSeznamu* _zacatek;
		void pridejOsobu(Entity::Osoba o);
		string najdiTelefon(string jmeno)const;
		string najdiTelefon(int id)const;

	public:
		TelefonniSeznam() : _zacatek(nullptr) {}
	};
}
#endif