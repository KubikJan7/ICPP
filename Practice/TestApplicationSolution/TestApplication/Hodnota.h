#ifndef HODNOTA_H
#define HODNOTA_H

#include "PrvekVyrazu.h"

template<typename Data>
struct Hodnota : PrvekVyrazu
{
private:
	Data data;
public:
	Hodnota(Data data) : data(data) {}
	~Hodnota() {}
	virtual std::string getType() override { return "Hodnota"; }

	char getData() { return data; }
};

#endif