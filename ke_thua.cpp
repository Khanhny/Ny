//ke_thua.cpp
#include"ke_thua.h"
int Level_1::GetA()
{
	return this->a;
}
int Level_1::GetB()
{
	return this->b;
}
void Level_1::SetA(int a, int b)
{
	this->a = a;
	this->b = b;
}
void Level_1::SetB(int a, int b)
{
	this->a = a;
	this->b = b;
}
Level_1::Level_1()
{
	this->a = 0;
	this->b = 0;
}
Level_1::Level_1(int a, int b)
{
	this->a = a;
	this->b = b;
}
long Level_1::operator+ (Level_1& s)
{
	return (this->a +this->b);
}
bool Level_1::SoSanh()
{
	if (a > 10 or b > 10)
	{
		cout << "vui long nhap a,b <=10";
	}
	else
	{
		return 0;
	}
}
istream& operator >>(istream& is,Level_1& s)
{
	cout << "nhap A: ";
	is >> s.a;
	cout << "nhap B: ";
	is >> s.b;
	return is;
}
ostream& operator <<(ostream& os, const Level_1& s)
{
	os << s.a <<"+" <<s.b<<"="<<s.a+s.b;
	return os;
}
Level_2::Level_2() :Level_1()
{
	this->a = 0;
	this->b = 0;
}
Level_2::Level_2(int a, int b) :Level_1(a, b)
{
	this->a = a;
	this->b = b;
}
long Level_2::operator -(Level_2& t)
{
	return 	this->a - this->b;
}
long Level_3::operator * (Level_3& n)
{
	return this->a * this->b;
}
Level_3::Level_3():Level_2()
{
	this->a = 0;
	this->b = 0;
}
Level_3::Level_3(int a, int b):Level_2( a, b)
{
	this->a = a;
	this->b = b;
}




//level 1: Chi co phep cong.a, b <= 10
////level 2 : Chi co phep cong va - .a, b <= 10
////level 3 : Chi co phep cong va - va * .a, b <= 10
////level 4 : Chi co phep cong va - .a, b <= 100
////level 5 : Chi co phep cong va - va * .a, b <= 100