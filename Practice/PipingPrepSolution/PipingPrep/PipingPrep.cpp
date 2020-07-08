#include <iostream>
#include <sstream>
#include <string>

#include "Potrubi.h"

using namespace std;

int main()
{
	try {
		ostringstream oss{};
		oss << 5 << '\n';
		oss << " O-O " << '\n';
		oss << "O--+O" << '\n';
		oss << "   I " << '\n';
		oss << "   I " << '\n';
		oss << "   O " << '\n';

		string potrubi{ oss.str() };

		istringstream iss{potrubi};
		Potrubi p{iss};
		cout << ((p.JePotrubiOk()) ? "Ok" : "Nefunguje!!!") << endl;
	}
	catch (...)
	{
		cout << "exception" << endl;
	}
}
