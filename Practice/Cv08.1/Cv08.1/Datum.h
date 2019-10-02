#ifndef _DATUM_H
#define _DATUM_H
struct Datum {
	int _den;
	int _mesic;
	int _rok;

	Datum(int den, int mesic, int rok);
	Datum();
};
#endif