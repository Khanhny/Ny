#pragma once
#include <iostream>
using namespace std;
class Fraction
{
private:
	// Tu so
	int numerator;
	// Mau so
	int denominator;
	
public:
	int GetNum();
	int GetDen();
	int GetLimit();
	void SetNum(int numerator);
	void SetDen(int denominator);
	Fraction(int numerator, int denominator);
	
	
	void Input(int numerator, int denominator);
	Fraction(int random);
	Fraction& operator ++();
	Fraction& operator --(); 

	Fraction operator ++(int ); 
	Fraction operator --(int ); 

	friend ostream& operator<<(ostream& os, const Fraction& fraction);
};