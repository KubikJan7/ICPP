#include"PrvekSeznamu.h"
#include"Osoba.h"
namespace Model {
	struct TelefonniSeznam {
		PrvekSeznamu* dalsi;
		Entity::Osoba data;
	};
}