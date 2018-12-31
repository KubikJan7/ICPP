#include "linkedList.h"
template<typename T>
LinkedList<T>::LinkedList() {
	vrchol = nullptr;
}
template<typename T>
void LinkedList<T>::insertLast(T data) {
	Element<T>* newE = new Element<T>;
	newE->data = data;
	newE->predchozi = nullptr;
	if (vrchol == nullptr) {
		vrchol == newE;
		delete newE;
	}
	else {
		newE->predchozi = vrcchol;
		vrchol = newE;
	}
}
template<typename T>
void LinkedList<T>::deleteLast() {
	Element* temp = new node;
	temp = vrchol;
	vrchol = vrchol->predchozi;
	delete temp;
}