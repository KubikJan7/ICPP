#ifndef DYNARRAY_H
#define DYNARRAY_H
#include "interfaces.h"
template<typename T>
struct DynArray : public IDynArray<T> {
public:
	DynArray();
	virtual ~DynArray();
	virtual void add(T element);
	virtual T& get(int index);
	virtual int count() const;
private:
	int asize;
	int itemcount;
	T* array;
};

template<typename T>
DynArray<T>::DynArray() {
	asize = 10;
	itemcount = 0;
	array = new T[asize];
}
template<typename T>
DynArray<T>::~DynArray() {
	delete[] array;
}
template<typename T>
void DynArray<T>::add(T element) {
	if (asize == itemcount) {
		T* tempAr = array;
		asize += 10;
		array = new T[asize];
	}
	array[itemcount] = element;
	itemcount++;
}
template<typename T>
T& DynArray<T>::get(int index) {
	for (int i = 0; i < itemcount; i++) {
		if (i == index) {
			return array[i];
		}
	}
	throw("Hledany prvek neexistuje.");
}
template<typename T>
int DynArray<T>::count() const {
	return itemcount;
}

#endif