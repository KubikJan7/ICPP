#ifndef HASHSET_H
#define HASHSET_H
#include "interfaces.h"
template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
struct HashSet: public IHashSet<T,HF,EF> {
	struct Hashnode {
		T data;
		Hashnode* next = nullptr;
		Hashnode(T element, Hashnode* next);
		Hashnode(){}
	};
public:
	HashSet() {}
	HashSet(int internalArraySize);
	virtual ~HashSet();
	virtual void add(T element);
	virtual bool isPresent(T element) const;
private:
	int asize;
	Hashnode** ahash;
};

template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
HashSet<T, HF, EF>::HashSet(int internalArraySize) {
	this->asize = internalArraySize;
	ahash = new Hashnode*[asize];
	for (int i = 0; i < asize; i++) {
		ahash[i] = nullptr;
	}
}
template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
HashSet<T, HF, EF>::~HashSet() {
	Hashnode* temp = new Hashnode;
	for (int i = 0; i < asize; i++) {
		while (ahash[i] != nullptr) {
			temp = ahash[i]->next;
			delete[] ahash[i];
			ahash[i] = temp;
		}
	}
	delete temp;
}
template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
void HashSet<T, HF, EF>::add(T element) {
	int i = HF(element) % asize;
	if (!isPresent(element)) {
		Hashnode* new_node = new Hashnode{ element,ahash[i] };
		ahash[i] = new_node;
	}
}
template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
bool HashSet<T, HF, EF>::isPresent(T element) const {
	int index = HF(element) % asize;
	Hashnode* node = new Hashnode;
	node = ahash[index];
	while(node!=nullptr){
		if (EF(element, node->data)) {
			delete node;
			return true;
		}
		node = node->next;
	}
	delete node;
	return false;
}
template<typename T, HashFunction<T> HF, EqualFunction<T> EF>
HashSet<T, HF, EF>::Hashnode::Hashnode(T element, Hashnode* next) {
	this->data = element;
	this->next = next;
}
#endif


