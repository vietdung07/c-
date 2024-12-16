#include <iostream>
#include <iomanip>
#include <exception>
// #include <algorithm>
#include <math.h>
using namespace std;
long long gcd(long long a, long long b)
{
	a = abs(a);
	b = abs(b);
	if (a == 0 || b == 0)
		return 0;
	while (b != 0)
	{
		long long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
long long lcm(long long a, long long b)
{
	a = abs(a);
	b = abs(b);
	if (a == 0 || b == 0)
		return 0;
	else
		return a * (b / gcd(a, b));
}
class divided_by_zero : public std::exception
{
public:
	const char *what() const noexcept override
	{
		return "Divided by zero error";
	}
};
class fraction
{
private:
public:
	long long numerator;
	long long denominator;
	fraction(long long _numerator, long long _denominator = 1) : numerator(_numerator), denominator(_denominator)
	{
		try
		{
			if (denominator == 0)
				throw divided_by_zero();
		}
		catch (divided_by_zero &k)
		{
			cout << k.what();
			exit(1);
		}
	}
	fraction() : numerator(0), denominator(1) {}
	fraction Simlify() const
	{
		fraction k = *this;
		if (k.numerator == 0)
			k.denominator = 1;
		else
		{
			long long a = gcd(k.numerator, k.denominator);
			long long temp_numerator = abs(k.numerator);
			long long temp_denominator = abs(k.denominator);
			short sign_num = k.numerator / temp_numerator;
			short sign_den = k.denominator / temp_denominator;
			if (sign_num * sign_den == 1)
				k.numerator = temp_numerator;
			else if (sign_num * sign_den == -1)
				k.numerator = -temp_numerator;
			k.numerator = k.numerator / a;
			k.denominator = temp_denominator / a;
		}
		return k;
	}
	fraction operator+(fraction other) const
	{
		fraction this_one = this->Simlify();
		other = other.Simlify();
		long long a = lcm(this_one.denominator, other.denominator);
		long long temp_numerator = this_one.numerator * (a / this_one.denominator) + other.numerator * (a / other.denominator);
		long long temp_denominator = a;
		long long k = gcd(temp_denominator, temp_numerator);
		temp_denominator = temp_denominator / k;
		temp_numerator = temp_numerator / k;
		return fraction(temp_numerator, temp_denominator);
	}
	fraction operator-(fraction other) const
	{
		fraction this_one = this->Simlify();
		other = other.Simlify();
		long long a = lcm(this_one.denominator, other.denominator);
		long long temp_numerator = this_one.numerator * (a / this_one.denominator) - other.numerator * (a / other.denominator);
		long long temp_denominator = a;
		long long k = gcd(temp_denominator, temp_numerator);
		temp_denominator = temp_denominator / k;
		temp_numerator = temp_numerator / k;
		return fraction(temp_numerator, temp_denominator);
	}
	fraction &operator+=(fraction other)
	{
		return (*this = *this + other);
	}
	fraction &operator-=(fraction other)
	{
		return (*this = *this - other);
	}
	operator double()
	{
		return double(this->numerator) / (this->denominator);
	}
};

ostream &operator<<(ostream &os, const fraction &k)
{
	if (k.denominator != 1)
		os << k.numerator << '/' << k.denominator;
	else
		os << k.numerator;
	return os;
}
int main()
{
	fraction k(52, 104);
	std::cout << k.Simlify() << std::endl;
	return 0;
}