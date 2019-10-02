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


		/*std::*/cout << "Hello" << " " << "world" << "!" << " " << 123456 << 123.456 << endl;

	int* ukazatel = nullptr;
	ukazatel = new int; //malloc(sizeof(int))
	*ukazatel = 123456;
	cout << *ukazatel << endl;

	delete ukazatel; //free(ukazatel)

	int len = 10;
	int*pole = new int[len];

	for (int i = 0; i < len; i++)
		pole[i] = i;

	int*t = new int[len + 10];
	for (int i = 0; i < len; i++)
		t[i] = pole[i];
	delete pole;
	pole = t;


	/*int cislo;
	cin >> cislo;
	cout << "Nacetl jsem:" << cislo << endl;
	*/
	int tmp;
	cin >> tmp;
	/*printf("Hello world/n");
	system("pause");*/
	return 0;
}
