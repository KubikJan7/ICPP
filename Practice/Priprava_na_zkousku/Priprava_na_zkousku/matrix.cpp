#include "pch.h"
#include "matrix.h"
#include<fstream>
#include<iostream>
using namespace std;


Matrix::~Matrix()
{
	for (int i = 0; i < radky;i++) {
		delete[] data[i];
	}
	delete[] data;
}

Matrix::Matrix(string filename) {
	int ch;
	ifstream in{};
	in.open(filename);
	in >> radky; in >> sloupce;
	data = new int*[radky];
	for (int i = 0; i < radky; i++) {
		data[i] = new int[sloupce];
		for (int j = 0; j < sloupce; j++) {
			in >> ch;
			data[i][j] = ch;
		}
	}
	in.close();
}
void Matrix::vypisMatici(Matrix* m) {
	cout << m->radky << " " << m->sloupce<<endl;
	for (int i = 0; i < m->radky; i++) {
		for (int j = 0; j < m->sloupce; j++) {
			cout << m->data[i][j]<<" ";
		}
		printf("\n");
	}
}
void Matrix::zapisDoSouboru(string filename, Matrix* m) {
	ofstream out{};
	out.open(filename);
	if (out.is_open()) {
		out << m->radky << " " << m->sloupce << endl;
		for (int i = 0; i < m->radky; i++) {
			for (int j = 0; j < m->sloupce; j++) {
				out << m->data[i][j] << " ";
			}
			out << endl;
		}
	}
	out.close();

}
