#include <db.h>
#include <helpful.h>
#include <iostream>
#include "simpleDbException.h"

using namespace std;

int main() {
	try {
		// Vytvoření db
		Db* db = Db::open("testdb");
		// Vytvoření tabulky
		auto customerId = Db::Field("id", FieldType::Integer);
		auto customerName = Db::Field("name", FieldType::String);
		auto customerSurname = Db::Field("surname", FieldType::String);
		auto customerEmail = Db::Field("email", FieldType::String);
		auto customerPasswd = Db::Field("password", FieldType::String);
		auto customerFields = combineToDefinition(customerId, customerName, customerSurname, customerEmail, customerPasswd);
		Table* customers = db->openOrCreateTable("customer", 5, customerFields);

		auto productId = Db::Field("id", FieldType::Integer);
		auto productName = Db::Field("name", FieldType::String);
		auto productPrice = Db::Field("price", FieldType::Double);
		auto productFields = combineToDefinition(productId, productName, productPrice);
		Table* products = db->openOrCreateTable("product", 3, productFields);

		auto purchaseId = Db::Field("id", FieldType::Integer);
		auto customerIdFK = Db::Field("customer_id", FieldType::Integer);
		auto productIdFK = Db::Field("product_id", FieldType::Integer);
		auto purchaseFields = combineToDefinition(purchaseId, customerIdFK, productIdFK);
		Table* purchases = db->openOrCreateTable("purchase", 3, customerFields);

		// Vložení řádku do tabulky	
		auto id = Db::Int(0);
		auto firstName = Db::String("Karel");
		auto lastName = Db::String("Novak");
		auto email = Db::String("novak@email.cz");
		auto password = Db::String("novak123");
		auto row = combineToRow(id, firstName, lastName, email, password);
		customers->insert(row);

		// Select
		auto it = customers->select();
		while (it->moveNext())
		{
			auto row = it->getRow();

			cout << row[0]->getInt() << ": " << row[1]->getString() << endl;
		}
		it->close();

		// Uložení tabulky na disk
		customers->commit();

		// Uzavření tabulky
		customers->close();

		// Uzavření db
		db->close();

		cin.get();
		return 0;
	}
	catch (WrongInputException & ex) {
		cout << ex.getMessage() << endl;
	}
	catch (InvalidOperationException & ex) {
		cout << ex.getMessage() << endl;
	}
	catch (LoadFileException & ex) {
		cout << ex.getMessage() << endl;
	}
}