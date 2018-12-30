#ifndef DYNARRAY_H
#define DYNARRAY_H
#include "interfaces.h"
template<typename T>
struct DynArray : public IDynArray<T> {
public:
	virtual ~DynArray();
	virtual void add(T element);
	virtual T& get(int index);
	virtual int count() const;
private:
	T pole[10];
};

template<typename T>
DynArray<T>::~DynArray() {

}
template<typename T>
void DynArray<T>::add(T element) {

}
template<typename T>
T& DynArray<T>::get(int index) {
	return pole[1];
}
template<typename T>
int DynArray<T>::count() const {
	int i = 0;
	return i;
}

#endif