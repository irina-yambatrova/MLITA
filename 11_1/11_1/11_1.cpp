/*Треугольник и точка (5)
В декартовой системе координат на плоскости заданы координаты вершин треугольника и еще
одной точки. Определить, принадлежит ли эта точка треугольнику.
Ввод из файла INPUT.TXT. В четырех строках находятся пары чисел - координаты точек.
Числа в первых трех строках - это координаты вершин треугольника, в четвертой строке -
координаты тестируемой точки.
Вывод в файл OUTPUT.TXT. Вывести In, если точка находится внутри треугольника, или Out -
если снаружи.
Ограничения: координаты вершин - целые числа, для любой точки выполняются следующие
условия: -1000000000 ≤ x, y ≤ 100000000, время 1 с.
*/

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "11_1.h"

using namespace std;

int FindArea(int ax, int ay, int bx, int by, int cx, int cy)
{
	return (abs((by - ay)*(cx - ax) - (bx - ax)*(cy - ay)))/2;
	
}

bool CheckPoint(int &ax, int &ay, int &bx, int &by, int &cx, int &cy, int &px, int &py)
{
	int mainArea = FindArea(ax, ay, bx, by, cx, cy),
		areaWithPoint1 = FindArea(ax, ay, bx, by, px, py),
		areaWithPoint2 = FindArea(bx, by, cx, cy, px, py),
		areaWithPoint3 = FindArea(cx, cy, ax, ay, px, py);

	if (areaWithPoint1 + areaWithPoint2 + areaWithPoint3 - mainArea > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ReadInputAndOutputData(ifstream &inputf, ofstream &outputf)
{
	
	if (!inputf.is_open() || !outputf.is_open())
	{
		cout << "Error: input.txt or output.txt is not open" << endl;
	}

	int ax, ay, bx, by, cx, cy, px, py;
	inputf >> ax;
	inputf >> ay;
	inputf >> bx;
	inputf >> by;
	inputf >> cx;
	inputf >> cy;
	inputf >> px;
	inputf >> py;

	if (!CheckPoint(ax, ay, bx, by, cx, cy, px, py))
	{
		outputf << "Out";
	}
	else
	{
		outputf << "In";
	}
	inputf.close();
	outputf.close();
}



