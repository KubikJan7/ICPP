template<typename TypDat, int PocatecniVelikost = 5, int RostouciKoeficient = 2>
struct RostouciKontejner {
public:
	TypDat* _data = new TypDat[PocatecniVelikost];
	int _velikostPole;
	int _pocetPlatnychPrvku;

	RostouciKontejner();
	~RostouciKontejner();
	bool jeMistoVPoli() const;
	void zvetsiPole();
	void pridej(const TypDat& o);
	TypDat& operator[](int index);
	TypDat operator[](int index)const;
	unsigned int pocet() const;
	void pridejNa(int index, const TypDat& o);
	void odeber(int index);

};

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::RostouciKontejner() {
	_data = new Typ[PocatecniVelikost];
	_velikostPole = PocatecniVelikost;
	_pocetPlatnychPrvku = 0;
}

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::~RostouciKontejner() {
	delete[] _data;
}

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
bool RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::jeMistoVPoli() const {
		return (_pocetPlatnychPrvku < _velikostPole);
}

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
void RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::zvetsiPole() {
	TypDat* pomocne = new TypDat[_velikostPole * RosouciKoeficient];
	for (int i = 0; i < _pocetPlatnychPrvku; i++) {
		pomocne[i] = _data[i];
	}
	delete[] _data;
	_data = pomocne;
	_velikostPole = _velikostPole * RostouciKoeficient;
}

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
void RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::pridej(const TypDat& o) {
	if (!jeMistoVPoli) 
		_unsignedPocetPrvku += 1;

	_data[_pocetPlatnychPrvku] = objekt;
	_pocetPlatnychPrvku++;
}

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
TypDat& RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::operator[](int index) {



}

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
TypDat RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::operator[](int index)const {

}

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
unsigned int RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::pocet() const {
	return _pocetPlatnychPrvku;
}

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
void RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::pridejNa(int index, const TypDat& o) {
	// 0-1-2-3-4-5-6-7-8-9
	// A-B-C-D-_-_-_-_-_-_
	

	for (int i = index; i < _pocetPlatnychPrvku - 1; i--) {
		_data[i + 1] = _data[i];
	}
	_data[index] = objekt;
	_pocetPlatnychPrvku++;
}

template <typename TypDat, int PocatecniVelikost, int RostouciKoeficient>
void RostouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::odeber(int index) {

	for (int i = index i < _pocetPlatnychPrvku; i++) {
		_data[i] = _data[i + 1];
		_pocetPlatnychPrvku--;
	}
}

