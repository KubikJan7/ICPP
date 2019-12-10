#ifndef SIMPLE_DB_EXCEPTION_H
#define SIMPLE_DB_EXCEPTION_H

#include <string>
struct SimpleDbException {
private:
	std::string message;
public:
	SimpleDbException(std::string message) :message(message) {};
	virtual std::string getMessage() { return message; };
};

struct InvalidOperationException : SimpleDbException {
	InvalidOperationException(std::string message) : SimpleDbException(message) {}
};

struct WrongInputException : SimpleDbException {
	WrongInputException(std::string message) : SimpleDbException(message) {}
};
#endif
