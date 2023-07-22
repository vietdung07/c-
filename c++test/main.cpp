#include <iostream>
#include <cmath>
#include <conio.h>
#include <utility>
#include <ctime>
#include <windows.h>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int gcd(int a, int b)
{
    while (a != 0 && b != 0)
        if (a > b)
            a = a % b;
        else
            b = b % a;
    return a + b;
}
std::pair<int, int> find_lcm_gcd(int g, long long l)
{
    if (l % g != 0)
        return std::pair<int, int>{0, 0};
    l = g * l;
    for (int i = sqrt(l); i >= 1; i--)
        if (l % i == 0 && gcd(i, l / i) == g)
            return std::pair<int, int>{i, l / i};
}
void _hoan_vi(vector<int> n, int k)
{
    for (int &i : n)
    ;
}
int main()
{
    return 0;
}
