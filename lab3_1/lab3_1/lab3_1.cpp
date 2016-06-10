/*
Имеется лестница, состоящая из N ступенек. При подъеме по лестнице заяц может прыгать на
любое количество ступенек от 1 до K. Сколько у зайца способов подъема по лестнице?
Ввод из файла INPUT.TXT. Единственная строка содержит целые положительные числа N и K.
Вывод  в файл OUTPUT.TXT. Выводится единственное число - количество способов подъема
по лестнице.
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long ways;

long long findWays(long numberOfSteps, long jumpOnNumberOfSteps)
{
	vector<long long> mass(sizeof(long long));
	mass[0] = 1;
	mass[1] = 1;
	size_t j;
	if (jumpOnNumberOfSteps == 1)
	{
		ways = numberOfSteps - 1;
	}
	else
	{
		for (size_t i= 2; i < numberOfSteps + 1; i++)
		{
			
			if (i - jumpOnNumberOfSteps < 0)
			{
				size_t j = 0;
			}
			else
			{
				 j = i - jumpOnNumberOfSteps;

			}
			for (; j < i; j++)
			{
				mass[i] += mass[j];
			}
		}
		 ways = mass[numberOfSteps];
	}
	return ways;
}

bool ReadInputAndPrintOutputData()
{
	ifstream inputf("input.txt");
	ofstream outputf("output.txt");
	if (!inputf.is_open() || !outputf.is_open())
	{
		outputf << "error!  input.txt or output.txt is not open";
	}
	int numberOfSteps, jumpOnNumberOfSteps;
	inputf >> numberOfSteps >> jumpOnNumberOfSteps;
	inputf.close();
	if ((1 <= jumpOnNumberOfSteps) && (jumpOnNumberOfSteps <= numberOfSteps) && (numberOfSteps <= 100))
	{
		outputf << findWays(numberOfSteps, jumpOnNumberOfSteps);
		return true;
		outputf.close();
	}
	else
	{
		return false;
	}
}



