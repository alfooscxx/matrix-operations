#include "matrix.h"

/*
Matrix basic operations
Matrices must be inputed line by line, through the gaps
Example:
0 0
0 0

! Check out that operations you will do can be defined !
  Better use square matrices
*/

enum types
{
	STOP, DISPLAY, SUMM, DIFFERENCE, EQUALITY, PRODUCT, SCALAR_PRODUCT, TRANSPOSITION, DETERMINANT, INVERSE
};

int main()
{
	std::string filename_1;
	std::string filename_2;
	std::cout << "Enter the name of the first file\n";
	std::cin >> filename_1;
	std::cout << "Enter the name of the second file\n";
	std::cin >> filename_2;
	matrix m1(filename_1);
	matrix m2(filename_2);
	unsigned short int type{};
	bool flag, stop = false;
	double scalar{0};

	std::cout << "0 - to stop the program\n";
	std::cout << "1 - to display the matrices\n";
	std::cout << "2 - to find out the summ\n";
	std::cout << "3 - to find out the difference\n";
	std::cout << "4 - to check for equality\n";
	std::cout << "5 - to find out the product\n";
	std::cout << "6 - to find out the product matrix on scalar\n";
	std::cout << "7 - to make the matrix transposited\n";
	std::cout << "8 - to find out the determinant\n";
	std::cout << "9 - to find out the inverse matrix\n";

	while (!stop)
	{
		std::cout << "What kind of operation would you choose?\n";
		std::cin >> type;
		switch (type)
		{
		case STOP:
			stop = true;
			break;
		case DISPLAY:
			std::cout << m1 << std::endl << m2;
			break;
		case SUMM:
			std::cout << m1 + m2;
			break;
		case DIFFERENCE:
			std::cout << m1 - m2;
			break;
		case EQUALITY:
			flag = (m1 == m2);
			std::cout << flag << std::endl;
			break;
		case PRODUCT:
			std::cout << "What order the product should be done in? 1/2\n";
			std::cin >> type;
			if (type == 1)
				std::cout << m1 * m2;
			else if (type == 2)
				std::cout << m2 * m1;
			else
				std::cout << "Incorrect order\n";
			break;
		case SCALAR_PRODUCT:
			std::cout << "Enter the scalar\n";
			std::cin >> scalar;
			std::cout << "Which matrix should be producted on scalar? 1/2\n";
			std::cin >> type;
			if (type == 1)
				std::cout << m1 * scalar;
			else if (type == 2)
				std::cout << m2 * scalar;
			else
				std::cout << "Incorrect number\n";
			break;
		case TRANSPOSITION:
			std::cout << "Which matrix should be transposited? 1/2\n";
			std::cin >> type;
			if (type == 1)
				std::cout << m1.t();
			else if (type == 2)
				std::cout << m2.t();
			else
				std::cout << "Incorrect number\n";
			break;
		case DETERMINANT:
			std::cout << "Which matrix determinant should be found out of? 1/2\n";
			std::cin >> type;
			if (type == 1)
			{
				std::cout << m1.determinant() << std::endl;
			}
			else if (type == 2)
			{
				std::cout << m2.determinant() << std::endl;
			}
			else
				std::cout << "Incorrect number\n";
			break;
		case INVERSE:
			std::cout << "Which matrix should be inversed? 1/2\n";
			std::cin >> type;
			if (type == 1)
				std::cout << m1.inverse();
			else if (type == 2)
				std::cout << m2.inverse();
			else
				std::cout << "Incorrect number\n";
			break;
		}
	}
	system("pause");
	return 0;
}