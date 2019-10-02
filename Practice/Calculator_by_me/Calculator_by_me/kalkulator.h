#ifndef KALKULATOR_H
#define KALKULATRO_H	
#include"prvekVyrazu.h"
#include"hodnota.h"
#include"operator.h"
#include<iostream>
using namespace std;
struct VyjimkaKalkulatoru {
};

template<typename Data, int Zaokrouhleni>
struct Kalkulator {
private:
	PrvekVyrazu** pole;
	int velPole;
	int pocPrvku;
public:
	Kalkulator();
	~Kalkulator();
	void pridejHodnotu(Data hodnota);
	void pridejOperator(char oper);
	Data vypocitej();
};
template<typename Data, int Zaokrouhleni>
Kalkulator<Data, Zaokrouhleni>::Kalkulator() {
	velPole = 100;
	pocPrvku = 0;
	pole = new PrvekVyrazu*[velPole];
	for (int i = 0; i < velPole; i++) {
		pole[i] = nullptr;
	}
}
template<typename Data, int Zaokrouhleni>
Kalkulator<Data, Zaokrouhleni>::~Kalkulator() {
	for (int i = 0; i < pocPrvku; i++) {
		delete pole[i];
	}
	delete[] pole;
}
template<typename Data, int Zaokrouhleni>
void Kalkulator<Data, Zaokrouhleni>::pridejHodnotu(Data hodnota) {
	pole[pocPrvku] = new Hodnota<Data>(hodnota);
	pocPrvku++;
}
template<typename Data, int Zaokrouhleni>
void Kalkulator<Data, Zaokrouhleni>::pridejOperator(char oper) {
	pole[pocPrvku] = new Operator(oper);
	pocPrvku++;
}
template<typename Data, int Zaokrouhleni>
Data Kalkulator<Data, Zaokrouhleni>::vypocitej() {
	if (pocPrvku == 0) {
		cout << "V poli se nenachazi zadne znaky." << endl;
		return 0;
	}

	Data vysledek = ((Hodnota<Data>*)pole[0])->getHodnota();
	for (int i = 1; i < pocPrvku; i += 2) {
		char oper = ((Operator*)pole[i])->getOperator();
		Data hod = ((Hodnota<Data>*)pole[i + 1])->getHodnota();
		switch (oper) {
		case '+':
			vysledek += hod;
			break;
		case '-':
			vysledek -= hod;
			break;
		case '*':
			vysledek *= hod;
			break;

		case '/':
			vysledek /= hod;
			break;
		default:
			cout << "Zadan nespravny operator." << endl;
		}
	}

	int misto = (int)pow(10, Zaokrouhleni);
	vysledek = round(vysledek*misto) / misto;

	return vysledek;

}
#endif