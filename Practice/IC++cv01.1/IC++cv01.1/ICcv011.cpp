// ICcv011.cpp: Definuje vstupní bod pro konzolovou aplikaci.
//


#include <iostream>

using namespace std;
struct Trojuhelnik {
	int a;
	int b;
	int c;
};

bool lzeSestrojit(Trojuhelnik t) {
	if (t.a + t.b > t.c&&t.a + t.c > t.b&&t.b + t.c > t.a)
	{
		return true;
	}
	else {
		return false;
	}
}

bool lzeSestrojit(Trojuhelnik* t) {
	if (t->a + t->b > t->c&&t->a + t->c > t->b&&t->b + t->c > t->a)
	{
		return true;
	}
	else {
		return false;
	}
}
void nactiTrojuhelnik(Trojuhelnik &t) {
	Trojuhelnik* ukazatel = new Trojuhelnik;
	cout << "Zadejte stranu a:" << endl;
	cin >> t.a;
	cout << "Zadejte stranu b:" << endl;
	cin >> t.b;
	cout << "Zadejte stranu c:" << endl;
	cin >> t.c;

	ukazatel->a = t.a;
	ukazatel->b = t.b;
	ukazatel->c = t.c;

	if (lzeSestrojit(t)) {
		cout << "\nLze sestrojit." << " " << "Obvod: " << ukazatel->a + ukazatel->b + ukazatel->c << "\n" << endl;
	}
	else {
		cout << "\nNelze sestrojit.\n" << endl;
	}

	cout << "---------------------------" << endl;
}

void nactiPole(Trojuhelnik* pole, int length) {
	for (int i = 0; i < length; i++)
	{
		cout << "Trojuhelnik c. " << i + 1 << endl;
		cout << "---------------------------\n" << endl;

		Trojuhelnik t{};
		nactiTrojuhelnik(t);
		pole[i] = t;
	}
}


int main()
{
	int pocetTroj;
	cout << "---------------------------" << endl;
	cout << "Zadejte pocet troujuhelniku" << endl;
	cout << "---------------------------" << endl;
	cin >> pocetTroj;
	cout << "---------------------------" << endl;
	Trojuhelnik* pole = new Trojuhelnik[pocetTroj];
	nactiPole(pole, pocetTroj);

	delete[] pole;

	system("Pause");
	return 0;
}
