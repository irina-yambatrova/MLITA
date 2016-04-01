/*
9.2(3)Студент Вася отыскивает простые числа в диапазоне от 1 до N (1 ≤  N ≤ 109). Если число M, не
превосходящее N, не делится на  2, 3 и 5, Вася называет его “простоватым”. По заданному
значению N найти количество простоватых чисел.
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

unsigned SearchAmountOfPrimesNumbers(const unsigned &N)
{
	unsigned counter = 0;
	for (size_t i = 1; i <= N; ++i)
	{
		if ((i % 2 != 0) && (i % 3 != 0) && (i % 5 != 0)) 
		{
			++counter;
		}
	}
	return counter;
};

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "Error input data! You should enter 1 arguments ! <file name> \n example:input.txt";
		return EXIT_FAILURE;
	}

	ifstream inputf(argv[1]);
	ofstream outputf("output.txt");
	if (!inputf.is_open() || !outputf.is_open())
	{
		cout << "Error: input.txt or output.txt is not open" << endl;
		return EXIT_FAILURE;
	}

	unsigned number;
	inputf >> number;
	outputf << SearchAmountOfPrimesNumbers(number);

	inputf.close();
	outputf.close();

	return EXIT_SUCCESS;
}

