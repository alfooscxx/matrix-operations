#include "matrix.h"

matrix::matrix(std::string filename)
{
	try
	{
		std::ifstream in(filename.c_str());
		if (!in.is_open())
			throw 1;
		in >> (*this);
		in.close();
	}
	catch (int e)
	{
		if (e == 1)
			std::cout << "\nFile cannot be opened!\n";
		system("pause");
		exit(e);
	}
}

matrix::matrix(unsigned width, unsigned length)
{
	try
	{
		this->width = width;
		this->length = length;

		if ((width < 0) || (length < 0))
			throw -1;

		this->table.resize(width);
		for (unsigned i = 0; i < width; i++)
			(*this)[i].resize(length);
	}
	catch (int e)
	{
		if (e == -1)
			std::cout << "\nNon-positive matrix size\n";
		system("pause");
		exit(e);
	}
}

matrix::matrix()
{
	table.resize(0);
	width = 0;
	length = 0;
}

const matrix matrix::t()
{
	const unsigned w { this->width }, l { this->length };
	matrix t(l, w);
	for (unsigned i = 0; i < l; i++)
	{
		for (unsigned j = 0; j < w; j++)
		{
			t[i][j] = (*this)[j][i];
		}
	}
	return t;
}

const matrix matrix::inverse()
{
	try
	{
		if (this->width != this->length)
			throw -1;
		const double d { this->determinant() };
		const unsigned n { this->width };
		const matrix t { this->t() };
		if (d == 0)
			throw - 1;
		matrix I(n, n);
		matrix minor(n-1, n-1);
		for (unsigned i = 0; i < n; i++)
		{
			for (unsigned j = 0; j < n; j++)
			{
				for (unsigned k = 0; k < n - 1; k++)
				{
					for (unsigned l = 0; l < n - 1; l++)
					{
						if ((k < i)&&(l < j))
						{
							minor[k][l] = t[k][l];
						}
						if (( k < i)&&(l >= j))
						{
							minor[k][l] = t[k][l+1];
						}
						if ((k >= i) && (l < j))
						{
							minor[k][l] = t[k+1][l];
						}
						if ((k >= i) && (l >= j))
						{
							minor[k][l] = t[k+1][l+1];
						}
					}
				}
				I[i][j] = pow(-1, i + j)*minor.determinant();
			}
		}
		I /= d;
		return I;
	}
	catch(int e)
	{
		if (e == -1)
			std::cout << "\nThis matrix cannot be inversed\n";
		system("pause");
		exit(e);
	}
}

const double matrix::determinant()
{
	try
	{
		if (this->width != this->length)
			throw -1;
		const unsigned n { this->width };
		double det{};
		if (n == 1)
			return (this->table[0][0]);
		else
		{
			matrix minor(n - 1, n - 1);
			for (unsigned j = 0; j < n; j++)
			{
				for (unsigned k = 0; k < n - 1; k++)
				{
					for (unsigned l = 0; l < n - 1; l++)
					{
						if (l < j)
						{
							minor[k][l] = (*this)[k + 1][l];
						}
						else
						{
							minor[k][l] = (*this)[k + 1][l + 1];
						}
					}
				}
				det += (this->table[0][j]) * (minor.determinant()) * pow(-1, j);
			}
			return det;
		}
	}
	catch (int e)
	{
		if (e == -1)
			std::cout << "\nDeterminant cannot be found\n";
		system("pause");
		exit(e);
	}
}
