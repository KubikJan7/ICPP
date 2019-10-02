#pragma once
//#ifndef _PES_H
//#define _PES_H
#include <string>

struct Uctenka {
private:
	int cisloUctenky;
	double castka;
	double dph;

public:
	//Uctenka(int id, double castka, double dph);
	void precistUctenku();
	int getCisloUctenky() const;
	void setCisloUctenky(int cisloUctenky);
	double getCastka()const;
	void setCastka(int castka);
	double getDph()const;
	void setDph(double Dph);

};
//#endif