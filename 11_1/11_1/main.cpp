#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include "11_1.h"
using namespace std;

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Error input data! You should enter 2 arguments ! <input file name> <output file name> ";
		return EXIT_FAILURE;
	}
	auto pointBefore = std::chrono::system_clock::now();

	ifstream inputf(argv[1]);
	ofstream outputf(argv[2]);
	ReadInputAndOutputData(inputf, outputf);

	auto pointAfter = std::chrono::system_clock::now();
	auto durationMsec = std::chrono::duration_cast<std::chrono::milliseconds>(pointAfter - pointBefore);
	std::cerr << "Total time: " << durationMsec.count() << "ms" << std::endl;
	return EXIT_SUCCESS;
}