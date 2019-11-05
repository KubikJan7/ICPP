#include "Datum.h"
Datum::Datum(int den, int mesic, int rok) {
	_den = den;
	_mesic = mesic;
	_rok = rok;
}

Datum::Datum() : _den(0), _mesic(0), _rok(0){

}