#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator);
    Fraction(int random);

    int GetNum();
    int GetDen();
    void SetNum(int numerator);
    void SetDen(int denominator);

    friend ostream& operator<<(ostream& os, const Fraction& f);
};
