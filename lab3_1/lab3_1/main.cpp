#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include "lab3_1.h"

int main()
{
	auto pointBefore = std::chrono::system_clock::now();

	ReadInputAndPrintOutputData();

	auto pointAfter = std::chrono::system_clock::now();
	auto durationMsec = std::chrono::duration_cast<std::chrono::milliseconds>(pointAfter - pointBefore);

	std::cerr << "Total time: " << durationMsec.count() << "ms" << std::endl;
	return EXIT_SUCCESS;
}