#include "TelefonniSeznam.h"
#include "MyException.h"
#include<iostream>

using namespace std;

void Model::TelefonniSeznam::pridejOsobu(Entity::Osoba o)
{
	PrvekSeznamu* novyPrvekSeznamu = new PrvekSeznamu{};
	novyPrvekSeznamu->data = o;
	novyPrvekSeznamu->dalsi = _zacatek;
	_zacatek = novyPrvekSeznamu;
}

string Model::TelefonniSeznam::najdiTelefon(string jmeno) const
{
	if (jmeno._Equal(""))
		throw WrongInputException("The input parameter is not valid.");
	PrvekSeznamu* prvekSeznamu = _zacatek;
	while (prvekSeznamu != nullptr) {
		if (prvekSeznamu->data.jmeno == jmeno)
			return prvekSeznamu->data.telefon;
		prvekSeznamu = prvekSeznamu->dalsi;
	}
	throw NoSuchElementException("Person with the specified id is not situated in the list.");
}

string Model::TelefonniSeznam::najdiTelefon(int id) const
{
	if (id <= 0)
		throw WrongInputException("The input parameter is not valid.");
	PrvekSeznamu* prvekSeznamu = _zacatek;
	while (prvekSeznamu != nullptr) {
		if (prvekSeznamu->data.id == id)
			return prvekSeznamu->data.telefon;
		prvekSeznamu = prvekSeznamu->dalsi;
	}
	throw NoSuchElementException("Person with the specified id is not situated in the list.");
}

void Model::TelefonniSeznam::smazSeznam()const
{
	PrvekSeznamu* prvek = _zacatek;
	while (prvek != nullptr) {
		PrvekSeznamu* tmp = prvek->dalsi;
		delete prvek;
		prvek = tmp;
	}
}

