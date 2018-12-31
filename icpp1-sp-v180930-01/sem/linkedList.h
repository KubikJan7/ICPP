#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
struct LinkedList {
	struct Element {
		T data;
		Element *predchozi;
	};
private:
	Element *vrchol;
public:
	LinkedList();
	void insertLast(T data);
	void deleteLast();
};
#endif