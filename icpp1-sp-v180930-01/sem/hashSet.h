#include "interfaces.h"
template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
struct HashSet: public IHashSet {
	virtual ~HashSet();
	virtual void add(T element);
	virtual bool isPresent(T element) const;
};

template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
HashSet<T, HF, EF>::~HashSet() {

}

template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
void HashSet<T, HF, EF>::add(T element) {

}

template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
bool HashSet<T, HF, EF>::isPresent(T element) const {

}
