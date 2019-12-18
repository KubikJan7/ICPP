#include <db.h>
#include <helpful.h>
#include <iostream>
#include "simpleDbException.h"
#include <iomanip>
#include "condition.h"
#include <tuple>

using namespace std;

int validateIntegerInput()
{
	int input;
	for (;;)
		if (cin >> input) { return input; }
		else
		{
			cout << "Please enter a valid integer value!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
}

double validateDoubleInput()
{
	double input;
	for (;;)
		if (cin >> input) { return input; }
		else
		{
			cout << "Please enter a valid double value!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
}

int chooseTable(Table* customers, Table* products, Table* purchases) {
	cout << "Select a table.\n\n";
	cout << "1) " << "'" << customers->getTableName() << "'\n";
	cout << "2) " << "'" << products->getTableName() << "'\n";
	cout << "3) " << "'" << purchases->getTableName() << "'\n";
	cout << "0) Cancel\n";

	cout << "\nChoice: ";
	return validateIntegerInput();
}

void printCustomerRow(Object** row)
{
	cout << left << setw(5) << row[0]->getInt() << setw(25) << row[1]->getString() << setw(25)
		<< row[2]->getString() << setw(25) << row[3]->getString() << setw(25) << row[4]->getString() << endl;
}

void printProductRow(Object** row)
{
	cout << left << setw(5) << row[0]->getInt() << setw(25) << row[1]->getString() << setw(10) << row[2]->getDouble() << endl;
}

void iterateThroughTable(Table* table, function<void(Object**)> callback)
{
	cout << endl;
	//Print field names
	int width;
	for (int i = 0; i < table->getFieldCount(); i++)
	{
		if (table->getFields()[i]->getType() == FieldType::Integer)
			width = 5;
		else if (table->getFields()[i]->getType() == FieldType::Double)
			width = 10;
		else
			width = 25;

		cout << left << setw(width) << table->getFields()[i]->getName();
	}
	cout << endl;
	auto it = table->select();
	cout << "-------------------------------------------------------------------------------------------" << endl;
	while (it->moveNext())
	{
		auto row = it->getRow();

		callback(row);
	}
	cout << "-------------------------------------------------------------------------------------------" << endl;
	it->close();
	cout << endl << "<<Press enter to go to the main menu>>";
	cin.get(); cin.get();
}

void updateRows(Object** row) {
	double value = row[2]->getDouble();
	row[2]->setDouble(value * 1.5);
}

tuple<Table*, Table*, Table*>createTables(Db* db) {
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
	return make_tuple(customers, products, purchases);
}

void insertRowsIntoTables(Table* customers, Table* products, Table* purchases) {
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

}

int main() {

	// Create db
	Db* db = Db::open("SimpleEshop");
	Table* customers, * products, * purchases;
	tie(customers, products, purchases) = createTables(db);
	insertRowsIntoTables(customers, products, purchases);

	int choice;
	do {
		try {
			system("cls");
			cout << "=================================" << endl;
			cout << "Welcome to '" << db->getDatabaseName() << "' database" << endl;
			cout << "=================================" << endl << endl;
			cout << "Please, use digits (0-9) for the application control.\n\n";
			cout << "1) Insert\n";
			cout << "2) Select\n";
			cout << "3) Update\n";
			cout << "4) Delete\n";
			cout << "5) Commit\n";
			cout << "0) Close\n";

			cout << "\nChoice: ";
			choice = validateIntegerInput();

			switch (choice) {
			case 1:
				system("cls");
				cout << "======\n";
				cout << "Insert\n";
				cout << "======\n\n";
				choice = chooseTable(customers, products, purchases);
				int id;
				switch (choice) {
				case 1:
				{
					string fName, lName, email, passwd;
					cout << "\nType in data for each row." << endl;
					cout << customers->getFields()[0]->getName() << ": ";
					id = validateIntegerInput();
					cout << customers->getFields()[1]->getName() << ": ";
					cin >> fName;
					cout << customers->getFields()[2]->getName() << ": ";
					cin >> lName;
					cout << customers->getFields()[3]->getName() << ": ";
					cin >> email;
					cout << customers->getFields()[4]->getName() << ": ";
					cin >> passwd;
					cout << endl;
					customers->insert(combineToRow(Db::Int(id), Db::String(fName), Db::String(lName), Db::String(email), Db::String(passwd)));
					break;
				}
				case 2:
				{
					string name;
					double price;
					cout << "\nType in data for each row." << endl;
					cout << products->getFields()[0]->getName() << ": ";
					id = validateIntegerInput();
					cout << products->getFields()[1]->getName() << ": ";
					cin >> name;
					cout << products->getFields()[2]->getName() << ": ";
					price = validateDoubleInput();
					cout << endl;
					products->insert(combineToRow(Db::Int(id), Db::String(name), Db::Double(price)));
					break;
				}
				break;
				case 3:
					int customerId;
					int productId;
					cout << "\nType in data for each row." << endl;
					cout << purchases->getFields()[0]->getName() << ": ";
					id = validateIntegerInput();
					cout << purchases->getFields()[1]->getName() << ": ";
					customerId = validateIntegerInput();
					cout << purchases->getFields()[2]->getName() << ": ";
					productId = validateIntegerInput();
					cout << endl;
					purchases->insert(combineToRow(Db::Int(id), Db::Int(customerId), Db::Int(productId)));
					break;
				case 0:
					choice = -1;
					break;
				}
				break;
			case 2:
				system("cls");
				cout << "======\n";
				cout << "Select\n";
				cout << "======\n\n";
				choice = chooseTable(customers, products, purchases);
				switch (choice)
				{
				case 1:

					iterateThroughTable(customers, printCustomerRow);
					break;

				case 2:
					iterateThroughTable(products, printProductRow);
					break;
				case 3:
				{
					cout << endl;
					//Print field names
					cout << left << setw(5) << purchases->getFields()[0]->getName() << setw(25) << "customer" << setw(25) << "product";
					cout << endl;
					auto it = purchases->select();
					cout << "-------------------------------------------------------------------------------------------" << endl;
					while (it->moveNext())
					{
						auto row = it->getRow();

						cout << left << setw(5) << row[0]->getInt() << setw(25) << customers->findRowById(row[1]->getInt())[2]->getString()
							<< setw(25) << products->findRowById(row[2]->getInt())[1]->getString() << endl;
					}
					cout << "-------------------------------------------------------------------------------------------" << endl;
					it->close();
					cout << endl << "<<Press enter to go to the main menu>>";
					cin.get(); cin.get();
					break;
				}
				case 0:
					choice = -1;
					break;
				}
				break;
			case 3:
				system("cls");
				cout << "======\n";
				cout << "Update\n";
				cout << "======\n\n";
				choice = chooseTable(customers, products, purchases);
				switch (choice)
				{
				case 1:
					cout << "Select type of update.\n\n";
					cout << "1) Update one row\n";
					cout << "2) Update whole table\n";
					cout << "3) Update rows specified by condition\n";
					cout << "0) Cancel";

					cout << "\nChoice: ";
					choice = validateIntegerInput();
					break;

				case 2:
					iterateThroughTable(products, printProductRow);
					break;
				case 3:
					break;
				case 0:
					choice = -1;
					break;
				}
				break;
			case 4:
				system("cls");
				cout << "======\n";
				cout << "Delete\n";
				cout << "======\n\n";
				choice = chooseTable(customers, products, purchases);
				switch (choice)
				{
				case 1:
					cout << "\nType in the id of a row to remove." << endl;
					customers->remove(validateIntegerInput());
					break;
				case 2:
					cout << "\nType in the id of a row to remove." << endl;
					products->remove(validateIntegerInput());
					break;
				case 3:
					cout << "\nType in the id of a row to remove." << endl;
					purchases->remove(validateIntegerInput());
					break;
				case 0:
					choice = -1;
					break;
				}
				break;
			case 5:
				cout << "\nTables were saved to files." << endl;
				customers->commit();
				products->commit();
				purchases->commit();
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			}
		}
		catch (WrongInputException & ex) {
			cout << endl << ex.getMessage() << endl;
			cout << endl << "<<Press any key to go to the main menu>>";
			cin.get(); cin.get();
		}
		catch (InvalidOperationException & ex) {
			cout << endl << ex.getMessage() << endl;
			cout << endl << "<<Press any key to go to the main menu>>";
			cin.get(); cin.get();
		}
		catch (LoadFileException & ex) {
			cout << endl << ex.getMessage() << endl;
			cout << endl << "<<Press enter to go to the main menu>>";
			cin.get(); cin.get();
		}
	} while (choice != 0);

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
	cout << "Id of the row which satisfies the given condition is: " << purchases->findRowId(condition) << "." << endl << endl;

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