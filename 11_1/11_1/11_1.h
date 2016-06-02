#pragma once
#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <chrono>

int FindArea(int ax, int ay, int bx, int by, int cx, int cy);
bool CheckPoint(int ax, int ay, int bx, int by, int cx, int cy, int px, int py);
void ReadInputAndOutputData(std::ifstream &inputf, std::ofstream &outputf);
