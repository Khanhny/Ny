#pragma once
#include <iostream>
#include<string.h>
#include <vector>
using namespace std;
class Point
{
private:
	double x, y;

public:
	double GetX();
	double GetY();
	void SetX(double _x);
	void SetY(double _y);
	float kc();
	int input();
	void point(int, int);
	bool operator();
	



};