struct Monstrum {
private:
	int hp;
	int maxHp;

public:
	void setHp(int hp);
	int getHp();

	void setMaxHp(int maxHp);
	int getMaxHp();
};

struct PohyblivyObjekt :Monstrum {

};