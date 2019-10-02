template <typename T>
struct Fronta {

public:
	void Vloz(T hodnota);
	T Odeber();
	bool Obsahuje(T hodnota) const;
	void ZpracujPrvky(void fukce(T));
	bool JePrazdna() const;
};