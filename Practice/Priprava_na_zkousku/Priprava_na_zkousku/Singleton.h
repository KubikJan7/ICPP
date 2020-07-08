#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>

struct Singleton
{
private:
	static Singleton* instance;
	Singleton() {}
public:
	static Singleton* getInstance();

	~Singleton();
	void WriteToConsole(std::string text);
};

#endif