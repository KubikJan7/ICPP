#ifndef FRONTA_H
#define FRONTA_H

template <typename T>
struct Fronta {
private:
	struct El {
		T hodnota;
		El* dalsi;
		El* predchozi;
	};

	El* prvni;
	El* posledni;
	int pocetPrvku;
public:
	Fronta() {
		prvni = posledni = nullptr;
	}

	Fronta(const Fronta& f) {
		El* it = f.prvni;
		while (it) {
			Vloz(it->hodnota);
			it = it->dalsi;
		}
	}

	~Fronta() {
		while (prvni) {
			El* tmp = prvni;
			prvni = prvni->dalsi;
			delete tmp;
		}
	}
	void Vloz(T hodnota) {
		posledni = new El{ hodnota, nullptr, posledni };
		if (!prvni)
			prvni = posledni;
		else
			posledni->predchozi->dalsi = posledni;
		pocetPrvku++;
	}

	T Odeber() {
		T hodnota = posledni->hodnota;
		El* tmp = posledni;

		if (posledni->predchozi) {
			posledni = posledni->predchozi;
			posledni->dalsi = nullptr;
		}
		else {
			posledni = nullptr;
			prvni = nullptr;
		}

		delete tmp;
		pocetPrvku--;
		return hodnota;
	}

	bool Obsahuje(T hodnota) const {
		El* el = prvni;
		while (el) {
			if (el->hodnota == hodnota)
				return true;

			el = el->dalsi;
		}
		return false;
	}

	using ApplyFunkce = void(*) (T);

	void ZpracujPrvky(ApplyFunkce f) const{
		El* el = prvni;
		while (el) {
			f(el->hodnota);

			el = el->dalsi;
		}
	}
	bool JePrazdna() const {
		return prvni == nullptr;
	}

	int GetPocetPrvku() const{
		return pocetPrvku;
	}
};

#endif