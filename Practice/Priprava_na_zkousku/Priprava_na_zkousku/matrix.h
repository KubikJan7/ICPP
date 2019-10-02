#ifndef MATRIX_H
#define MATRIX_H
#include<string>
struct Matrix
{
public:
	int radky;
	int sloupce;
	int** data;
	Matrix(std::string filename);
	~Matrix();
	void vypisMatici(Matrix* m);
	void zapisDoSouboru(std::string filename, Matrix* m);
};
#endif

