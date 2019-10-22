#include "MyException.h"

MyException::MyException(std::string message) : message(message)
{
}

std::string MyException::getMessage()
{
	return message;
}
