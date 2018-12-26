#ifndef DYNARRAY_H
#define DYNARRAY_H
#include "interfaces.h"
template<typename T>
struct DynArray : public IDynArray {
	virtual ~DynArray();
	virtual void add(T element);
	virtual T& get(int index);
	virtual int count() const;
};

template<typename T>
DynArray<T>::~DynArray() {

}
template<typename T>
void DynArray<T>::add(T element) {

}
template<typename T>
T& DynArray<T>::get(int index) {

}
template<typename T>
int DynArray<T>::count() const {

}

#endif