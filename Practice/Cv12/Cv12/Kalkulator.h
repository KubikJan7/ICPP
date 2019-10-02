#define N = 50

template<typename Data, int Zaokrouhleni>
struct Kalkulator {
	PrvekVyrazu** operace = new PrvekVyrazu[N];

	void pridejHodnotu(Data hodnota);
	void pridejOperator(char operat);
	Data vypocitej();
	Kalkulator();
	~Kalkulator();
};

template<typename Data, int Zaokrouhleni>
Kalkulator<Data, Zaokrouhleni>::Kalkulator() {
	velikostPole = 100;
	ocetPrvkuVpoli = 0;
	pole = new PrvekVyrazu*[velikostPole];
	for (int i = 0; i < velikostPole; i++)
		pole[i] = nullptr;
}
template<typename Data, int Zaokrouhleni>
Kalkulator<Data, Zaokrouhleni>::~Kalkulator() {
	delete[] pole;
}

template<typename Data, int Zaokrouhleni>
void Kalkulator<Data,Zaokrouhleni>::pridejHodnotu(Data hodnota) {
	for (i = 0; i < N; i++) {
		if (operace[i] == nullptr) {
			operace[i] == hodnota;
			return;
		}
	}
}

template<typename Data, int Zaokrouhleni>
void Kalkulator<Data, Zaokrouhleni>::pridejOperator(char oper) {
	for (i = 0; i < N; i++) {
		if (operace[i] == nullptr) {
			operace[i] == oper;
			return;
		}
	}

}

template<typename Data, int Zaokrouhleni>
Data Kalkulator<Data, Zaokrouhleni>::vypocitej() {
	Data vysledek;
	for (i = 0; i < N; i++) {
		if (i != 0) {
			if (typeid(operace[i]).name() == typeid(operace[i - 1]).name()) {
				throw "VyjimkaKalkulatoru";
			}
		}
		vysledek += i;
	}
}