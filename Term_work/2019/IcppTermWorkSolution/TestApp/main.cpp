#include <db.h>
#include <helpful.h>
#include <iostream>
#include "simpleDbException.h"
#include <iomanip>
#include "condition.h"

using namespace std;

void updateRows(Object** row) {
	double value = row[2]->getDouble();
	row[2]->setDouble(value * 1.2);
}

int main() {
	try {
		// Create db
		Db* db = Db::open("testdb");

		// Create table Customer
		auto customerId = Db::Field("id", FieldType::Integer);
		auto customerFirstName = Db::Field("first_name", FieldType::String);
		auto customerLastName = Db::Field("last_name", FieldType::String);
		auto customerEmail = Db::Field("email", FieldType::String);
		auto customerPasswd = Db::Field("password", FieldType::String);
		auto customerFields = combineToDefinition(customerId, customerFirstName, customerLastName, customerEmail, customerPasswd);
		Table* customers = db->openOrCreateTable("customer", 5, customerFields);
		// Create table Product
		auto productId = Db::Field("id", FieldType::Integer);
		auto productName = Db::Field("name", FieldType::String);
		auto productPrice = Db::Field("price", FieldType::Double);
		auto productFields = combineToDefinition(productId, productName, productPrice);
		Table* products = db->openOrCreateTable("product", 3, productFields);
		// Create table Purchase
		auto purchaseId = Db::Field("id", FieldType::Integer);
		auto customerIdFK = Db::Field("customer_id", FieldType::Integer);
		auto productIdFK = Db::Field("product_id", FieldType::Integer);
		auto purchaseFields = combineToDefinition(purchaseId, customerIdFK, productIdFK);
		Table* purchases = db->openOrCreateTable("purchase", 3, purchaseFields);

		// Insert rows into Customer	
		customers->insert(combineToRow(Db::Int(0), Db::String("Karel"), Db::String("Novak"), Db::String("novak@email.cz"), Db::String("novak123")));
		customers->insert(combineToRow(Db::Int(1), Db::String("Jan"), Db::String("Stary"), Db::String("stary@email.cz"), Db::String("stary123")));
		customers->insert(combineToRow(Db::Int(2), Db::String("Josef"), Db::String("Vyskocil"), Db::String("vyskocil@email.cz"), Db::String("vyskocil123")));
		customers->insert(combineToRow(Db::Int(3), Db::String("Frantisek"), Db::String("Jedly"), Db::String("jedly@email.cz"), Db::String("jedly123")));
		customers->insert(combineToRow(Db::Int(4), Db::String("Stepan"), Db::String("Dlouhy"), Db::String("dlouhy@email.cz"), Db::String("dlouhy123")));
		customers->insert(combineToRow(Db::Int(5), Db::String("David"), Db::String("Vysoky"), Db::String("vysoky@email.cz"), Db::String("vysoky123")));
		// Insert rows into Product
		products->insert(combineToRow(Db::Int(100), Db::String("Intel_Core_i5-9400"), Db::Double(5424)));
		products->insert(combineToRow(Db::Int(101), Db::String("AMD_Athlon_3000G"), Db::Double(1399)));
		products->insert(combineToRow(Db::Int(102), Db::String("AMD_A6-9500"), Db::Double(960)));
		products->insert(combineToRow(Db::Int(103), Db::String("Intel_Core_i5-9400F"), Db::Double(3999)));
		products->insert(combineToRow(Db::Int(104), Db::String("AMD_Ryzen_7_3700X"), Db::Double(8980)));
		products->insert(combineToRow(Db::Int(105), Db::String("Intel_Core_i7-9700K"), Db::Double(10410)));
		// Insert rows into Purchase
		purchases->insert(combineToRow(Db::Int(321), Db::Int(0), (Db::Int(105))));
		purchases->insert(combineToRow(Db::Int(322), Db::Int(1), (Db::Int(100))));
		purchases->insert(combineToRow(Db::Int(323), Db::Int(2), (Db::Int(102))));
		purchases->insert(combineToRow(Db::Int(324), Db::Int(3), (Db::Int(101))));
		purchases->insert(combineToRow(Db::Int(325), Db::Int(4), (Db::Int(104))));
		purchases->insert(combineToRow(Db::Int(326), Db::Int(5), (Db::Int(103))));
		purchases->insert(combineToRow(Db::Int(327), Db::Int(0), (Db::Int(101))));

		// Delete row from Customer
		customers->remove(3);
		// Delete row from Purchase
		purchases->remove(3);

		// Select from Customer
		auto custIterator = customers->select();
		cout << "-------------------------------------------------------------------------------------------" << endl;
		while (custIterator->moveNext())
		{
			auto row = custIterator->getRow();

			cout << left << setw(5) << row[0]->getInt() << setw(25) << row[1]->getString() << setw(25)
				<< row[2]->getString() << setw(25) << row[3]->getString() << setw(25) << row[4]->getString() << endl;
		}
		cout << "-------------------------------------------------------------------------------------------" << endl;
		custIterator->close();

		// Select from Product
		auto prodIterator = products->select();
		cout << "-----------------------------------" << endl;
		while (prodIterator->moveNext())
		{
			auto row = prodIterator->getRow();

			// Update price of the product with id 105
			if (row[0]->getInt() == 105)
				row[2]->setDouble(12000);

			cout << left << setw(5) << row[0]->getInt() << setw(25) << row[1]->getString() << setw(10) << row[2]->getDouble() << endl;
		}
		cout << "-----------------------------------" << endl;
		prodIterator->close();

		// Select from Purchase
		auto purIterator = purchases->select();
		cout << "-------------" << endl;
		while (purIterator->moveNext())
		{
			auto row = purIterator->getRow();

			cout << left << setw(5) << row[0]->getInt() << setw(5) << row[1]->getInt() << setw(5) << row[2]->getInt() << endl;
		}
		cout << "-------------" << endl;
		purIterator->close();

		// Select with condition
		ICondition* condition = new Condition{};
		auto customIterator = customers->select(condition);
		cout << "-------------------------------------------------------------------------------------------" << endl;
		while (customIterator->moveNext())
		{
			auto row = customIterator->getRow();
			cout << left << setw(5) << row[0]->getInt() << setw(25) << row[1]->getString() << setw(25)
				<< row[2]->getString() << setw(25) << row[3]->getString() << setw(25) << row[4]->getString() << endl;
		}
		cout << "-------------------------------------------------------------------------------------------" << endl;
		customIterator->close();

		// Update rows meeting the defined condition
		products->update(condition, &updateRows);

		// Find a row id by the defined condition
		cout<<"Id of the row which satisfies the given condition is: "<<purchases->findRowId(condition)<<"."<<endl<<endl;

		// Save tables to files
		customers->commit();
		products->commit();
		purchases->commit();

		// Close tables
		customers->close();
		products->close();
		purchases->close();

		// Close db
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