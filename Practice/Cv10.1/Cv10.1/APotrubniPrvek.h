
struct APotrubniPrvek {
	virtual ~APotrubniPrvek() {}
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const = 0;
	int _x;
	int _y;
};
