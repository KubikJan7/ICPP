#ifndef HODNOTA_H
#define HODNOTA_H
#include "PrvekVyrazu.h"
template<typename Data>
struct Hodnota : PrvekVyrazu
{
private:
	Data hodnota;
public:
	Hodnota(Data hodnota);
	Data getHodnota();
	virtual std::string getTyp() const override;
};

#endif

template<typename Data>
inline Hodnota<Data>::Hodnota(Data hodnota)
{
	this->hodnota = hodnota;
}

template<typename Data>
inline Data Hodnota<Data>::getHodnota()
{
	return hodnota;
}

template<typename Data>
inline std::string Hodnota<Data>::getTyp() const
{
	return "hodnota";
}
