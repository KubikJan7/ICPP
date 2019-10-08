#ifndef ELEMENT_H
#define ELEMENT_H
template<typename T>
struct Element {
	T data;
	Element *predchozi;
};
#endif