#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using line = std::vector<double>;

class matrix
{
public:
	matrix(std::string filename);
	matrix(unsigned width , unsigned length);
	matrix();
	unsigned width;
	unsigned length;

	const matrix t();
	const matrix inverse();
	const double determinant();

	matrix &operator=(const matrix &m);
	line &operator[](int index);
	const line &operator[](int index) const;
	friend matrix operator+(const matrix &m1, const matrix &m2);
	friend matrix operator-(const matrix &m1, const matrix &m2);
	friend bool operator==(const matrix &m1, const matrix &m2);
	friend matrix operator*(matrix &m, double k);
	friend matrix &operator*=(matrix &m, double k);
	friend matrix operator/(matrix &m, double k);
	friend matrix &operator/=(matrix &m, double k);
	friend matrix operator*(double k, matrix &m);
	friend matrix operator/(double k, matrix &m);
	friend matrix operator*(const matrix &m1, const matrix &m2);
	friend std::ostream &operator<<(std::ostream &out, const matrix &m);
	friend std::ostream &operator>>(std::istream &in, matrix &m);
	
private:
	std::vector <line> table;
};
