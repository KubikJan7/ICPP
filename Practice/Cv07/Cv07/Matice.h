#include <string>
#include <iostream>

using namespace std;

template<typename T>
struct Matice {
public:
	T** data;
	int radky;
	int sloupce;

	Matice(int radky, int sloupce);
	Matice(const Matice<T>& m);
	~Matice();
	void Nastav(int radek, int sloupec, T hodnota);
	void NastavZ(T* pole);
	T& Dej(int radek, int sloupec);
	const T& Dej(int radek, int sloupec) const;

	template<typename R>
	Matice<R> Pretypuj() const;

	Matice Transpozice() const;
	Matice Soucin(const Matice& m) const;
	Matice Soucin(T skalar) const;
	Matice Soucet(const Matice& m) const;
	Matice Soucet(T skalar) const;

	bool JeShodna(const Matice& m) const;
	void Vypis() const;
};




template<typename T>
Matice<T>::Matice(int radky, int sloupce) {
	this->radky = radky;
	this->sloupce = sloupce;
	data = new T*[radky];
	for (int i = 0; i < radky; i++) {
		data[i] = new T[sloupce];
		for (int j = 0; j < sloupce; j++) {
			data[i][j] = 0;
		}
	}
}

template<typename T>
Matice<T>::Matice(const Matice<T>& m) {
	radky = m.radky;
	sloupce = m.sloupce;
	data = new T*[radky];
	for (int i = 0; i < radky; i++) {
		data[i] = new T[sloupce];
		for (int j = 0; j < sloupce; j++) {
			data[i][j] = m.data[i][j];
		}
	}
}

template<typename T>
Matice<T>::~Matice() {
	for (int i = 0; i < radky; i++) {
		delete data[i];
	}
	delete data;
}

template<typename T>
void Matice<T>::Nastav(int radek, int sloupec, T hodnota) {
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			if (i == radek && j == sloupec) {
				data[i][j] = hodnota;
			}
		}
	}

}

template<typename T>
void Matice<T>::NastavZ(T* pole) {
	int poc = 0;
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			data[i][j] = pole[poc++];
		}
	}
}

template<typename T>
T& Matice<T>::Dej(int radek, int sloupec) {
	try {
		if (radek>radky&&sloupec>sloupce) {
			throw 1;
		}
	}
	catch (int i) {
		cout << "Neplatny index." << i;
	}
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {

			if (radek == i && sloupec == j) {
				return data[i][j];
			}
		}
	}
}

template<typename T>
const T& Matice<T>::Dej(int radek, int sloupec) const {
	try {
		if (radek > radky&&sloupec > sloupce) {
			throw 1;
		}
	}
	catch (int i) {
		cout << "Neplatny index." << i;
	}
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {

			if (radek == i && sloupec == j) {
				return data[i][j];
			}
		}
	}
}

template<typename T>
template<typename R>
Matice<R> Matice<T>::Pretypuj() const {
	Matice<R> m{ radky,sloupce };
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			m.data[i][j] = (R)data[i][j];
		}
	}
	return m;
}

template<typename T>
Matice<T> Matice<T>::Transpozice() const {
	Matice<T> m{ sloupce,radky };
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			m.data[j][i] = data[i][j];
		}
	}
	return m;
}

template<typename T>
Matice<T> Matice<T>::Soucin(const Matice& m) const {
	try {
		if (sloupce != m.radky) {
			throw 1;
		}
	}
	catch (int i) {
		cout << "Dane matice se neshoduji." << i;
	}

	Matice<T> mat{ radky,sloupce };
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < m.sloupce; j++) {
			for (int k = 0; k < sloupce; k++) {
				mat.data[i][j] += data[i][k] * m.data[k][j];
			}
		}
	}
	return mat;
}

template<typename T>
Matice<T> Matice<T>::Soucin(T skalar) const {
	Matice<T> mat{ radky,sloupce };
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			mat.data[i][j] = data[i][j] * skalar;
		}
	}
	return mat;
}

template<typename T>
Matice<T> Matice<T>::Soucet(const Matice& m) const {
	try {
		if (radky != m.radky&&sloupce != m.sloupce) {
			throw 1;
		}
	}
	catch (int i) {
		cout << "Dane matice se neshoduji." << i;
	}

	Matice<T> mat{ radky,sloupce };
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			mat.data[i][j] = data[i][j] + m.data[i][j];
		}
	}
	return mat;
}

template<typename T>
Matice<T> Matice<T>::Soucet(T skalar) const {
	Matice<T> mat{ radky,sloupce };
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			mat.data[i][j] = data[i][j] + skalar;
		}
	}
	return mat;
}

template<typename T>
bool Matice<T>::JeShodna(const Matice& m) const {
	if (m.radky == radky && m.sloupce == sloupce) {
		for (int i = 0; i < radky; i++) {
			for (int j = 0; j < sloupce; j++) {
				if (data[i][j] != m.data[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
void Matice<T>::Vypis() const {
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			cout << data[i][j] << "  ";
		}
		printf("\n");
	}
	printf("\n");
}