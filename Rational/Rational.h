#pragma once
#include<iostream>
using namespace std;
class Rational
{
public:
	Rational(int numerator=0, int denominator=1) :
		_numerator(numerator),_denominator(denominator)
	{};
	~Rational() {}; //{ cout << "Dtor is called" << endl; };
private:
	int _numerator;//·Ö×Ó
	int _denominator;//·ÖÄ¸
};

