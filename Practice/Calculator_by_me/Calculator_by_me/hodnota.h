#ifndef HODNOTA_H
#define HODNOTA_H
#include"prvekVyrazu.h"
template<typename Data>
struct Hodnota:PrvekVyrazu
{
private:
	Data hodnota;
public:
	Hodnota();
	Hodnota(Data hodnota);
	virtual ~Hodnota();
	virtual bool jeOperator()const;
	virtual bool jeHodnota()const;
	Data getHodnota();
};
template<typename Data>
Hodnota<Data>::Hodnota()
{
}
template<typename Data>
Hodnota<Data>::Hodnota(Data hodnota) {
	this->hodnota = hodnota;
}
template<typename Data>
Hodnota<Data>::~Hodnota()
{
}
template<typename Data>
bool Hodnota<Data>::jeOperator()const { return false; }
template<typename Data>
bool Hodnota<Data>::jeHodnota()const { return true; }
template<typename Data>
Data Hodnota<Data>::getHodnota() {
	return this->hodnota;
}
#endif

