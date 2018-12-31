#include "linkedList.h"
template<typename T>
LinkedList<T>::LinkedList() {
	vrchol = nullptr;
}
template<typename T>
void LinkedList<T>::insertLast(T data) {
	Element* newE = new Element;
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
	Element* temp = new Element;
	temp = vrchol;
	vrchol = vrchol->predchozi;
	delete temp;
}