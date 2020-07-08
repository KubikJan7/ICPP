#include "pch.h"
#include "Singleton.h"
#include <string>
#include <iostream>

using namespace std;

Singleton* Singleton::instance = new Singleton;

Singleton* Singleton::getInstance()
{
	return instance;
}

Singleton::~Singleton()
{
}

void Singleton::WriteToConsole(std::string text)
{
	cout << text << endl;
}
