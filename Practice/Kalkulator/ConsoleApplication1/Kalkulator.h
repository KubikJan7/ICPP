#pragma once

struct VyjimkaKalkulatoru {
};

template <typename Data, int Zaokrouhleni>
struct Kalkulator
{
private:
	PrvekVyrazu** pole;
	int velikostPole;
	int pocetPrvkuVpoli;

public:
	Kalkulator() {
		velikostPole = 100;
		pocetPrvkuVpoli = 0;
		pole = new PrvekVyrazu*[velikostPole];
		for (int i = 0; i < velikostPole; i++)
			pole[i] = nullptr;
	}

	~Kalkulator() {
		for (int i = 0; i < pocetPrvkuVpoli; i++)
			delete pole[i];
		delete[] pole;
	}

	void pridejHodnotu(Data hodnota) {
		if (pocetPrvkuVpoli == velikostPole)
			throw "Nejak to preteklo";

		pole[pocetPrvkuVpoli] = new Hodnota<Data>{ hodnota };
		pocetPrvkuVpoli++;
	}

	void pridejOperator(char oper) {
		if (pocetPrvkuVpoli == velikostPole)
			throw "Nejak to preteklo";

		pole[pocetPrvkuVpoli] = new Operator{ oper };
		pocetPrvkuVpoli++;
	}

	Data vypocitej() const {
		if (pocetPrvkuVpoli == 0)
			return 0;

		if (pole[0]->jeHodnota() == false)
			throw VyjimkaKalkulatoru{};

		Data mezivysledek = ((Hodnota<Data>*)pole[0])->getHodnota();

		for (int i = 1; i < pocetPrvkuVpoli; i += 2) {
			if (pole[i]->jeHodnota() || i + 1 >= pocetPrvkuVpoli ||
				pole[i + 1]->jeOperator())
				throw VyjimkaKalkulatoru{};

			char oper = ((Operator*)pole[i])->getOperator();
			Data operand = ((Hodnota<Data>*)pole[i + 1])->getHodnota();

			switch (oper) {
			case '+':
				mezivysledek += operand;
				break;

			case '-':
				mezivysledek -= operand;
				break;

			case '*':
				mezivysledek *= operand;
				break;

			case '/':
				if (operand == 0)
					throw VyjimkaKalkulatoru{};

				mezivysledek /= operand;
				break;
			}
		}

		// zaokrouhli to
		double nasobek = pow(10, Zaokrouhleni);
		mezivysledek = round(mezivysledek * nasobek) / nasobek;

		return mezivysledek;
	}
};


