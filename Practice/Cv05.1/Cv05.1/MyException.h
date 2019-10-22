#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <string>
struct MyException {
private:
	std::string message;
public:
	MyException(std::string message);
	virtual std::string getMessage();
};

struct NoSuchElementException : MyException {
	NoSuchElementException(std::string message) : MyException(message) {}
};

struct WrongInputException : MyException {
	WrongInputException(std::string message) : MyException(message) {}
};
#endif
