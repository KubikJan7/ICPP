#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a + b > c&&a + c > b&&b + c > a)
		cout << "Jde sestrojit"<<" "<<"Obvod:" << a+b+c<<endl;
	return 0;
}
