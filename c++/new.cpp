#include <iostream>
#include <iomanip>
#include <exception>
#include <math.h>
using namespace std;
long gcd(long a, long b)
{
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0)
        return 0;
    while (a != 0 && b != 0)
        if (a > b)
            a = a % b;
        else
            b = b % a;
    return (a != 0) ? a : b;
}
long lcm(long a, long b)
{
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0)
        return 0;
    else
        return a * b / gcd(a, b);
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
    long numerator;
    long denominator;
    fraction(long _numerator, long _denominator = 1) : numerator(_numerator), denominator(_denominator)
    {
        try
        {
            if (denominator == 0)
                throw divided_by_zero();
        }
        catch (divided_by_zero &k)
        {
            cout << k.what();
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
            int a = gcd(k.numerator, k.denominator);
            short sign_num = k.numerator / abs(k.numerator);
            short sign_den = k.denominator / abs(k.denominator);
            if (sign_num * sign_den == 1)
                k.numerator = abs(k.numerator);
            else if (sign_num * sign_den == -1)
                k.numerator = -abs(k.numerator);
            k.numerator = k.numerator / a;
            k.denominator = abs(k.denominator) / a;
        }
        return k;
    }
    fraction operator+(fraction other) const
    {
        fraction this_one = this->Simlify();
        other = other.Simlify();
        long a = lcm(this_one.denominator, other.denominator);
        long temp_numerator = this_one.numerator * (a / this_one.denominator) + other.numerator * (a / other.denominator);
        long temp_denominator = a;
        long k = gcd(temp_denominator, temp_numerator);
        temp_denominator = temp_denominator / k;
        temp_numerator = temp_numerator / k;
        return fraction(temp_numerator, temp_denominator);
    }
    fraction operator-(fraction other) const
    {
        fraction this_one = this->Simlify();
        other = other.Simlify();
        long a = lcm(this_one.denominator, other.denominator);
        long temp_numerator = this_one.numerator * (a / this_one.denominator) - other.numerator * (a / other.denominator);
        long temp_denominator = a;
        long k = gcd(temp_denominator, temp_numerator);
        temp_denominator = temp_denominator / k;
        temp_numerator = temp_numerator / k;
        return fraction(temp_numerator, temp_denominator);
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
    fraction a(100);
    fraction b(-5, -6);
    fraction k = a - b;
    cout << b;
    return 0;
}