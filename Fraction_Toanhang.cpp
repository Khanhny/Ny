#include "Fraction.h"
#include<iostream>
using namespace std;

int Fraction::GetNum()
{
    return numerator;
}

int Fraction::GetDen()
{
    return denominator;
}

void Fraction::SetNum(int numerator)
{
    this->numerator = numerator;
}

void Fraction::SetDen(int denominator)
{
    this->denominator = denominator;
}

Fraction::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        this->numerator = 0;
        this->denominator = 1;
    }
    else
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
}

Fraction::Fraction(int n)
{
    this->numerator = n;
}
//++f
Fraction& Fraction::operator ++ ()
{
    ++numerator;
    return *this;// Tra ve doi tuong hien tai
}
//--f
Fraction& Fraction::operator --()
{
    -- numerator;
    return *this;
}
//f++
Fraction Fraction::operator ++(int) 
{
    Fraction Kq = *this;  //sao chep doi tuong hien tai vao bien Kq(ban sao)
    ++ numerator;  //kq.numerator de thay doi ban sao cho ko lam anh huong tham so chinh
    return Kq;
}
//f--
Fraction Fraction::operator --(int) 
{
    Fraction Kq = *this;
    -- numerator;
    return Kq;
}
ostream& operator<<(ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os; // Phải trả về luồng để cho phép nối chuỗi
}