#pragma once
#include "stdafx.h"

using namespace sf;

sf::View view;//�������� sfml ������ "���", ������� � �������� �������

void getplayercoordinateforview(float x, float y) 
{
	float tempX = x; float tempY = y;//��������� ����� ������ � ��������� ��, ����� ������ ����

	
	if (x <= 490) tempX = 490;//������� �� ���� ����� �������	

	view.setCenter(tempX, tempY); //������ �� �������, ��������� ��� ����������. 

}
