#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string prime_factor(int n)
{
    string tmp = "";
    for (int i = 2; i * i <= n; i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if (count > 0)
        {
            if (count == 1)
                tmp += to_string(i);
            else if (count > 1)
                tmp += to_string(i) + "^" + to_string(count);
            if (n > 1)
                tmp += " * ";
        }
    }
    if (n > 1)
        tmp += to_string(n);
    return tmp;
}
int count_factors(int n)
{
    int number_factors = 1;
    for (int i = 2; i * i <= n; i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        number_factors *= (count + 1);
    }
    if (n > 1)
        number_factors *= 2;
    return number_factors;
}
int main()
{
    freopen("main.out", "w", stdout);
    int max = 1;
    for (int i = 1; i <= 10000; i++)
    {
        int temp = count_factors(i);
        cout << i << ' ' << prime_factor(i) << ' ' << temp << endl;
        if (temp > count_factors(max))
            max = i;
    }
    cout << max;
    // cout << prime_factor(2147483647) << ' ' << count_factors(2147483647);
    return 0;
}