// Cv06.0.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
using namespace std;
template<typename Object/*, class Object2, int Pocet*/>
struct SpojovySeznam {
private:
	struct PrvekSeznamu {
		PrvekSeznamu* dalsi;
		Object data;
	};

	PrvekSeznamu* prvni;

public:
	SpojovySeznam() {
		prvni = nullptr;
	}
	~SpojovySeznam();
	void Vloz(Object data);
	Object& Dej(int i);

	template<typename JinyTyp>
	void metoda(JinyTyp jt) {

	}
};

template<typename Object>
SpojovySeznam<Object>::~SpojovySeznam() {
	PrvekSeznamu* tmp = prvni;
	while (prvni != nullptr) {
		prvni = prvni->dalsi;
		delete tmp;
		tmp = prvni;
	}
}
template<typename Object>
void SpojovySeznam<Object>::Vloz(Object data) {
	PrvekSeznamu* ps = new PrvekSeznamu{};
	ps->dalsi = nullptr;
	ps->data = data;

	PrvekSeznamu* posledni = prvni;
	while (posledni->dalsi != nullptr) {
		posledni = posledni->dalsi;
	}

	posledni->dalsi = ps;
}
template<typename MujDivnoObjekt>
MujDivnoObjekt& SpojovySeznam<MujDivnoObjekt>:: Dej(int i) {
	PrvekSeznamu* ps = prvni;
	for (int i = 0; i < idx; i++)
		ps = ps->dalsi;

	return ps->data;
}

int main()
{
	SpojovySeznam<int> seznam{};
	seznam.Vloz(10);
	seznam.Vloz(20);
	seznam.Vloz(30);
	seznam.Vloz(40);

	cout << seznam.Dej(0) << endl;
	cout << seznam.Dej(1) << endl;
	cout << seznam.Dej(2) << endl;
	cout << seznam.Dej(3) << endl;

	SpojovySeznam<string> seznamStringu{};
	seznamStringu.Vloz("prvni string");
	seznamStringu.Vloz("druhy string");

	cout << seznamStringu.Dej(1) << endl;
	cout << typeid(seznam).raw_name() << endl;
	cout << typeid(seznam).raw_name() << endl;

}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
