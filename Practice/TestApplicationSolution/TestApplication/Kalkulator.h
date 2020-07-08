#ifndef KALKULATOR_H
#define KALKULATOR_H

#include "Hodnota.h"
#include "Operator.h"
#include "VyjimkaKalkulatoru.h"

template<typename Data, int Zaokrouhleni>
struct Kalkulator
{
private:
	PrvekVyrazu** prvkyVyrazu;
	int length;
	int count;
public:
	Kalkulator(int length);
	~Kalkulator();
	void pridejHodnotu(Data hodnota);
	void pridejOperator(char oper);
	Data vypocitej();
};

#endif

template<typename Data, int Zaokrouhleni>
inline Kalkulator<Data, Zaokrouhleni>::Kalkulator(int length)
{
	this->length = length;
	this->count = 0;

	prvkyVyrazu = new PrvekVyrazu * [length];

	for (int i = 0; i < length; i++)
	{
		prvkyVyrazu[i] = nullptr;
	}
}

template<typename Data, int Zaokrouhleni>
inline Kalkulator<Data, Zaokrouhleni>::~Kalkulator()
{
	for (int i = 0; i < length; i++)
	{
		delete prvkyVyrazu[i];
	}

	delete[] prvkyVyrazu;
}

template<typename Data, int Zaokrouhleni>
inline void Kalkulator<Data, Zaokrouhleni>::pridejHodnotu(Data hodnota)
{
	prvkyVyrazu[count++] = new Hodnota<Data>(hodnota);
}

template<typename Data, int Zaokrouhleni>
inline void Kalkulator<Data, Zaokrouhleni>::pridejOperator(char oper)
{
	prvkyVyrazu[count++] = new Operator(oper);
}

template<typename Data, int Zaokrouhleni>
inline Data Kalkulator<Data, Zaokrouhleni>::vypocitej()
{
	Data vysledek = dynamic_cast<Hodnota<Data>*>(prvkyVyrazu[0])->getData();

	for (int i = 1; i < count; i += 2)
	{
		Data h = dynamic_cast<Hodnota<Data>*>(prvkyVyrazu[i + 1])->getData();
		switch (((Operator*)prvkyVyrazu[i])->getOperator())
		{
		case '+':
			vysledek += h;
			break;
		case '-':
			vysledek -= h;
			break;
		case '*':
			vysledek *= h;
			break;
		case '/':
			if (h == 0)
				throw VyjimkaKalkulatoru("Error: Division by zero.");
			vysledek /= h;
			break;
		default:
			break;
		}
	}

	int decPlaces = pow(10,Zaokrouhleni);
	return round(vysledek*decPlaces)/decPlaces;
}
