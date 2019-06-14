#include "matrix.h"

matrix & matrix::operator=(const matrix & m)
{
	if (this == &m)
		return *this;
	const unsigned w { m.width }, l { m.length };
	table.resize(w);
	for (unsigned n = 0; n < w; n++)
		table[n].resize(l);
	width = w;
	length = l;
	for (unsigned i = 0; i < w; i++)
	{
		for (unsigned j = 0; j < l; j++)
		{
			(*this)[i][j] = m[i][j];
		}
	}
	return *this;
}

line &matrix::operator[](const int index)
{
	return table[index];
}

const line &matrix::operator[](const int index) const
{
	return table[index];
}

matrix operator-(const matrix & m1, const matrix & m2)
{
	try
	{
		if ((!(m1.length == m2.length)) || (!(m1.width == m2.width)))
			throw - 1;
		unsigned w { m1.width }, l { m1.length };
		matrix m(w, l);
		for (unsigned i = 0; i < w; i++)
		{
			for (unsigned j = 0; j < l; j++)
			{
				m[i][j] = m1[i][j] - m2[i][j];
			}
		}
		return(m);
	}
	catch (int e)
	{
		if (e == -1)
			std::cout << "\nMatrix sizes don't match\n";
		system("pause");
		exit(e);
	}
}

bool operator==(const matrix & m1, const matrix & m2)
{
	if ((m1.width != m2.width) || (m1.length != m2.length))
		return false;
	unsigned w { m1.width }, l { m1.length };
	bool flag { true };
	for (unsigned i = 0; i < w; i++)
	{
		for (unsigned j = 0; j < l; j++)
		{
			if (m1[i][j] != m2[i][j])
				flag = false;
		}
	}
	return flag;
}

matrix operator+(const matrix & m1, const matrix & m2)
{
	try
	{
		if ((!(m1.length == m2.length)) || (!(m1.width == m2.width)))
			throw - 1;
		unsigned w { m1.width };
		unsigned l { m1.length };
		matrix m(w, l);
		for (unsigned i = 0; i < w; i++)
		{
			for (unsigned j = 0; j < l; j++)
			{
				m[i][j] = m1[i][j] + m2[i][j];
			}
		}
		return m;
	}
	catch (int e)
	{
		if (e == -1)
			std::cout << "\nMatrix sizes don't match\n";
		system("pause");
		exit(e);
	}
}

matrix operator*(matrix &m, double k)
{
	for (unsigned i = 0; i < m.width; i++)
	{
		for (unsigned j = 0; j < m.length; j++)
		{
			m[i][j] *= k;
		}
	}
	return m;
}

matrix &operator*=(matrix &m, double k)
{
	for (unsigned i = 0; i < m.width; i++)
	{
		for (unsigned j = 0; j < m.length; j++)
		{
			m[i][j] *= k;
		}
	}
	return m;
}

matrix operator/(matrix &m, double k)
{
	try
	{
		if (k == 0)
			throw 0;
		for (unsigned i = 0; i < m.width; i++)
		{
			for (unsigned j = 0; j < m.length; j++)
			{
				m[i][j] /= k;
			}
		}
		return m;
	}
	catch (int e)
	{
		if (e == 0)
			std::cout << "\nDividing by zero\n";
		system("pause");
		exit(e);
	}
}

matrix &operator/=(matrix &m, double k)
{
	try
	{
		if (k == 0)
			throw 0;
		for (unsigned i = 0; i < m.width; i++)
		{
			for (unsigned j = 0; j < m.length; j++)
			{
				m[i][j] /= k;
			}
		}
		return (m);
	}
	catch (int e)
	{
		if (e == 0)
			std::cout << "\nDividing by zero\n";
		system("pause");
		exit(e);
	}
}

matrix operator*(double k, matrix &m)
{
	for (unsigned i = 0; i < m.width; i++)
	{
		for (unsigned j = 0; j < m.length; j++)
		{
			m[i][j] *= k;
		}
	}
	return m;
}

matrix operator/(double k, matrix &m)
{
	try
	{
		if (k == 0)
			throw 0;
		for (unsigned i = 0; i < m.width; i++)
		{
			for (unsigned j = 0; j < m.length; j++)
			{
				m[i][j] /= k;
			}
		}
		return m;
	}
	catch (int e)
	{
		if (e == 0)
			std::cout << "\nDividing by zero\n";
		system("pause");
		exit(e);
	}
}

matrix operator*(const matrix &m1, const matrix &m2)
{
	try
	{
		matrix m(m1.width, m2.length);
		double value{};
		for (unsigned i = 0; i < m1.width; i++)
		{
			for (unsigned j = 0; j < m2.length; j++)
			{
				for (unsigned r = 0; r < m1.length; r++)
				{
					value += m1[i][r] * m2[r][j];
				}
				m[i][j] = value;
				value = 0.0;
			}
		}
		return m;
	}
	catch (int e)
	{
		if (e==-1)
			std::cout<<"\nMatrix sizes don't match\n";
		system("pause");
		exit(e);
	}
}

std::ostream & operator<<(std::ostream & out, const matrix & m)
{
	for (unsigned i = 0; i < m.width; i++)
	{
		for (unsigned j = 0; j < m.length; j++)
		{
			out << m[i][j];
			if (j == m.length - 1)
				out << std::endl;
			else
				out << " ";
		}
	}
	return out;
}

std::ostream & operator>>(std::istream & in, matrix & m)
{
	try
	{
		m.width = 0;
		int space_number{};
		char symbol { '0' };
		double value{};
		while (!in.eof())
		{
			m.table.push_back(line());
			while (symbol != '\n')
			{
				in >> value;
				m[m.width].push_back(value);
				in.get(symbol);
				if (symbol == ' ')
					space_number++;
				if (in.eof())
				{
					if (space_number != 0)
						space_number--;
					break;
				}
			}
			if (m.width == 0)
				m.length = space_number + 1;
			else
			{
				if (space_number + 1 != m.length)
					throw - 1;
			}
			space_number = 0;
			symbol = '0';
			m.width++;
		}
	}
	catch (int e)
	{
		if (e == -1)
			std::cout << "\nMatrix was written in a wrong way\n";
		system("pause");
		exit(e);
	}
}
