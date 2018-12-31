#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
struct LinkedList {
	struct Element {
		T data;
		Element *previous = nullptr;
		Element() {}
	};
private:
	Element *peak;
public:
	~LinkedList();
	LinkedList();
	void insertLast(T data);
	void deleteLast();
};
template<typename T>
LinkedList<T>::LinkedList() {
	peak = nullptr;
}
template<typename T>
LinkedList<T>::~LinkedList() {
	Element* temp = new Element;
	while (peak != nullptr) {
		temp = peak->previous;
		delete peak;
		peak = temp;
	}
	delete temp;
}
template<typename T>
void LinkedList<T>::insertLast(T data) {
	Element* newE = new Element;
	newE->data = data;
	newE->previous = nullptr;
	if (peak == nullptr) {
		peak == newE;
		delete newE;
	}
	else {
		newE->previous = peak;
		peak = newE;
	}
}
template<typename T>
void LinkedList<T>::deleteLast() {
	Element* temp = new Element;
	temp = peak;
	peak = peak->previous;
	delete temp;
}

#endif