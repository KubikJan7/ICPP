#ifndef KALKULATOR
#define KALKULATOR

#include "Hodnota.h"
#include "Operator.h"
#include <string>
#include <iostream>
#include <math.h>
#include "VyjimkaKalkulatoru.h"

template<typename Data, int Zaokrouhleni>
struct Kalkulator
{
private:
	PrvekVyrazu** operace;
	int maxPocetOperaci;

public:
	Kalkulator(int maxPocetOperaci);
	~Kalkulator();
	void pridejHodnotu(Data hodnota);
	void pridejOperator(char oper);
	Data vypocitej();
};

#endif

template<typename Data, int Zaokrouhleni>
inline Kalkulator<Data, Zaokrouhleni>::Kalkulator(int maxPocetOperaci)
{
	this->maxPocetOperaci = maxPocetOperaci;
	operace = new PrvekVyrazu * [maxPocetOperaci];
	for (int i = 0; i < maxPocetOperaci; i++)
	{
		operace[i] = nullptr;
	}
}

template<typename Data, int Zaokrouhleni>
inline Kalkulator<Data, Zaokrouhleni>::~Kalkulator()
{
	for (int i = 0; i < maxPocetOperaci; i++)
	{
		if (operace[i] == nullptr)
			break;
		delete operace[i];
	}
	delete[] operace;
}

template<typename Data, int Zaokrouhleni>
inline void Kalkulator<Data, Zaokrouhleni>::pridejHodnotu(Data hodnota)
{
	for (int i = 0; i < maxPocetOperaci; i++)
	{
		if (operace[i] == nullptr)
		{
			operace[i] = new Hodnota<Data>{ hodnota };
			return;
		}
	}
}

template<typename Data, int Zaokrouhleni>
inline void Kalkulator<Data, Zaokrouhleni>::pridejOperator(char oper)
{
	if (oper != '+' && oper != '-' && oper != '*' && oper != '/')
		throw VyjimkaKalkulatoru("Zadejte validni operator");

		for (int i = 0; i < maxPocetOperaci; i++)
		{
			if (operace[i] == nullptr)
			{
				operace[i] = new Operator{ oper };
				return;
			}
		}
}

template<typename Data, int Zaokrouhleni>
inline Data Kalkulator<Data, Zaokrouhleni>::vypocitej()
{
	char lastOperator = NULL;
	Data result = NULL;
	for (int i = 0; i < maxPocetOperaci; i++)
	{
		if (operace[i] == nullptr)
			break;
		if (operace[i]->getTyp() == "hodnota") {
			Data hodnota = ((Hodnota<Data>*)operace[i])->getHodnota();
			if (lastOperator) {
				if (lastOperator == '+')
					result += hodnota;
				else if (lastOperator == '-')
					result -= hodnota;

				else if (lastOperator == '*')
					result *= hodnota;

				else if (lastOperator == '/') {
					if (hodnota == 0)
						throw VyjimkaKalkulatoru("Nulou delit nelze.");
					result /= hodnota;
				}
			}
			else
				result = hodnota;

		}
		else if (operace[i]->getTyp() == "operator")
			lastOperator = ((Operator*)operace[i])->getOperator();


	}
	return round(result * pow(10, Zaokrouhleni)) / pow(10, Zaokrouhleni);
}
