#include "pch.h"
#include <iostream>
#include "StatickyObjekt.h"
#include <typeinfo>
#include "Hra.h"
using namespace std;
int main()
{
	Hra hra{10};
	
	StatickyObjekt s1{ 0,Skala };
	s1.setX(10);
	s1.setY(5);
	hra.vlozObjekt(&s1);

}

