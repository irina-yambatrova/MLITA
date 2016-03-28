/*
Студент Вася отыскивает простые числа в диапазоне от 1 до N (1 ≤  N ≤ 109). Если число M, не
превосходящее N, не делится на  2, 3 и 5, Вася называет его “простоватым”. По заданному
значению N найти количество простоватых чисел.
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void SearchAmountOfProstovatyhNumbers(ifstream &inputf, ofstream &outputf) 
{
	char ch[60];
	int N;
	int i;
	int counter = 0;
	inputf >> ch;
	N = atoi(ch);
	for (i = 1; i <= N; i++)
	{
		if ((i % 2 != 0) && (i % 3 != 0) && (i % 5 != 0)) //простоватые числа
		{
			//cout << "Prime nimber "<< i;
			counter++;	
		}
	}
	outputf << counter;
};

int main(int argc, char * argv[])
{
	if (argc == 2)
	{
		//ifstream inputf("input.txt");
		ifstream inputf(argv[1]);
		ofstream outputf("output.txt");
		if (!inputf.is_open())
		{
			cout << "Error: input.txt is not open" << endl;
			return 1;
		}
		else
		{
			SearchAmountOfProstovatyhNumbers(inputf, outputf);
			cout << "Program is successfully";
		}
	}
	else
	{
		cout << "Error input data! You should enter 1 arguments ! <file name> \n example:input.txt";
		return 1;
	}
	return 0;
}

