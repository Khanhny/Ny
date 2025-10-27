#pragma once
#include<iostream>
using namespace std;
class Level_1
{
protected:
	int a, b;
public:
	int GetA();
	int GetB();
	void SetA(int a,int b);
	void SetB(int a, int b);
	Level_1();
	Level_1(int a,int b);
	long operator+ (Level_1 & s);
	bool SoSanh();
	friend istream& operator >>(istream& is,Level_1& s);
	friend ostream& operator <<(ostream& os,const Level_1& s);
};
class Level_2: public Level_1
{
public:
	long operator -(Level_2& t);
	Level_2();
	Level_2(int a, int b);
};
class Level_3: public Level_2
{
public:
	long operator * (Level_3& n);
	Level_3();
	Level_3(int a, int b);
};
class Level_4
{

};
class Level_5
{

};

//level 1: Chi co phep cong. a,b<=10
//level 2 : Chi co phep cong va - .a, b <= 10
//level 3 : Chi co phep cong va - va * .a, b <= 10
//level 4 : Chi co phep cong va - .a, b <= 100
//level 5 : Chi co phep cong va - va * .a, b <= 100


