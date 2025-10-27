#include"OPERATOR.h"
using namespace std;
int Fraction::GetNum()
{
	return num;

}
int Fraction::GetDen()
{
	return den;
}
void Fraction::SetNum(int num)
{
	this->num = num;
}
void Fraction::SetDen(int den)
{
	this->den = den;
}
Fraction::Fraction()
{
	this->num = 0;
	this->den = 1;
}
Fraction::Fraction(int num, int den)
{
	if (den == 0)
	{
		this->num = 0;
		this->den = 1;

	}
	else
	{
		this->num = num;
		this->den = den;
	}
}
Fraction Fraction::operator + (Fraction& ps)
{
	return Fraction(this->num * ps.den + this->den * ps.num,
		this->den * ps.den);
}

 ostream& operator <<(ostream& o, const Fraction& ps)
{
	o << ps.num << "/" <<ps.den;
	return o;
}

