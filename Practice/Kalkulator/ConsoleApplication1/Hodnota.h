#pragma once
template<typename Data>
struct Hodnota : PrvekVyrazu {
private:
	Data hodnota;

public:
	Hodnota(Data h) : hodnota(h) {
	}

	Data getHodnota() const { return hodnota; }

	virtual bool jeOperator() const override { return false; }
	virtual bool jeHodnota() const override { return true; }
};
