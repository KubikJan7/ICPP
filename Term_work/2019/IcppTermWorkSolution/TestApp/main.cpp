#include <db.h>
#include <helpful.h>
#include <iostream>
#include "simpleDbException.h"

using namespace std;

int main() {
	try {
		// Vytvoření db
		Db* db = Db::open("testdb");
		//// Vytvoření tabulky
		auto idField = Db::Field("id", FieldType::Integer);
		auto nameField = Db::Field("name", FieldType::String);
		auto userFields = combineToDefinition(idField, nameField);
		Table* t = db->openTable("person");
		Table* t2 = db->openTable("user");
		//Table* users = db->openOrCreateTable("users", 2, userFields);

		//// Vložení řádku do tabulky	
		//auto id = Db::Int(15);
		//auto name = Db::String("Josef");
		//auto row = combineToRow(id, name);
		//users->insert(row);

		//// Select
		//auto it = users->select();
		//while (it->moveNext()) 
		//{
		//	auto row = it->getRow();

		//	cout << row[0]->getInt() << ": " << row[1]->getString() << endl;
		//}
		//it->close();

		//// Uložení tabulky na disk
		//users->commit();

		//// Uzavření tabulky
		//users->close();

		//// Uzavření db
		//db->close();

		//cin.get();
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