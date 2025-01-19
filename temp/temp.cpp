#if 0
#include <iostream>
#define MAX 28
#define RES 3
bool bino_co_array[MAX];
int Main_arr[RES];
bool sub_arr[RES];
int temp[MAX];
int n = RES;
int cur = 1;
int count = 0;
void check()
{
    int sum = 0;
    if (temp[0] != 0)
    {
        for (int i = 0; i < 6; i++)
        {
            sum *= 10;
            sum += temp[i];
        }
        if (sum % 45 == 0)
        {
            std::cout << sum << '\n';
            count++;
        }
    }
}
void permute(int k)
{
    if (n == k)
    {
        check();
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            if (sub_arr[i] == false)
            {
                sub_arr[i] = true;
                temp[k] = Main_arr[i];
                permute(k + 1);
                sub_arr[i] = false;
            }
        }
    }
}
void binomial_coefficient_gen(int k)
{
    if (n == k - 1)
    {
        std::cout << Main_arr[0] << ' ' << Main_arr[1] << ' ' << Main_arr[2] << std::endl;
        if (Main_arr[0] + Main_arr[1] + Main_arr[2] == 27)
            count++;
    }
    else
    {
        int temp = cur;
        for (int i = temp; i < MAX; i++)
        {
            bino_co_array[i] = true;
            Main_arr[k - 1] = i;
            cur = i + 1;
            binomial_coefficient_gen(k + 1);
            bino_co_array[i] = false;
        }
    }
}
int main()
{
    freopen("main.out", "w", stdout);
    binomial_coefficient_gen(1);
    std::cout << count;
    return 0;
}
#endif
#if 0
#include <iostream>
int main()
{
    int count = 0;
    for (int i = 100035; i <= 999990; i += 45)
    {
        bool flag2 = true;
        int digits[10] = {0};
        int temp = i;
        while (temp > 0)
        {
            if (digits[temp % 10] <= 0)
                digits[temp % 10]++;
            else
            {
                flag2 = false;
                break;
            }
            temp /= 10;
        }
        if (flag2)
            count++;
    }
    std::cout << count;
    return 0;
}
#endif
#if 0
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <string>
#define MAX 3
bool bino_co_array[17];
int res[MAX];
int cur = 1;
int count = 0;
void binomial_coefficient_gen(int k)
{
    if (k == MAX)
    {
        int product = 1;
        for (int &i : res)
        {
            product *= i;
        }
        if (product % 128 == 0)
        {
            for (int &i : res)
            {
                std::cout << i << ' ';
            }
            std::cout << '\n';
            count++;
        }
    }
    else
    {
        int temp = cur;
        for (int i = temp; i <= 16; i++)
        {
            bino_co_array[i] = true;
            res[k] = i;
            cur = i + 1;
            binomial_coefficient_gen(k + 1);
            bino_co_array[i] = false;
        }
    }
}

#endif
#if 0
#include <iostream>
#include <set>
int table[4][4] = {0};
int count = 0;

void Try(int k)
{
    if (k == 16)
    {
        int check1[5] = {0};
        int check2[5] = {0};
        bool flag = true;
        for (int i = 0; i < 4; i++)
        {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < 4; j++)
            {
                sum1 += table[i][j];
                sum2 += table[j][i];
            }
            if (sum1 == 0 || sum2 == 0)
            {
                flag = false;
                break;
            }
            if (check1[sum1] == 0)
                check1[sum1]++;
            else
            {
                flag = false;
                break;
            }
            if (check2[sum2] == 0)
                check2[sum2]++;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            count++;
    }
    else
    {
        table[k / 4][k % 4] = 0;
        Try(k + 1);
        table[k / 4][k % 4] = 1;
        Try(k + 1);
    }
}
int main()
{
    Try(0);
    std::cout << count;
    return 0;
}
#endif
#if 0
#include <iostream>
#include <cstdint>
#include <bitset>
#include <ctime>
#include <windows.h>
#include <limits.h>
long long fastPower(long long a, int n)
{
    long long res = 1;
    while (n)
    {
        if (n & 1)
            res *= a;
        a *= a;
        n = n >> 1;
    }
    return res;
}
int digitsCount(long long n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}
bool check(long long n)
{
    int count = digitsCount(n);
    int res = 0;
    int temp = n;
    while (n)
    {
        res += fastPower(n % 10, count);
        n /= 10;
    }
    return res == temp;
}
int main()
{
    for (int i = 1; i <= INT_MAX; i++)
    {
        if (check(i))
            std::cout << i << '\n';
    }
    std::cout << std::flush;
    return 0;
}
#endif
#if 0
#include <iostream>
inline int gcd(int a, int b)
{
    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    freopen("main.out", "w", stdout);
    for (int m = 2; m <= 1000; m++)
    {
        for (int n = 1; n < m; n++)
        {

            int a = m * m - n * n, b = 2 * m * n, c = m * m + n * n;
            if (gcd(a, b) == 1)
            {
                if (a > b)
                    std::swap(a, b);
                std::cout << a << ' ' << b << ' ' << c << '\n';
            }
        }
    }
    return 0;
}
#endif
#if 0
#include <iostream>
#include <cmath>
inline int gcd(int a, int b)
{
    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
inline bool isSquare(int n)
{
    int t = sqrt(n);
    if (t * t == n)
        return true;
    return false;
}
int main()
{
    freopen("main.out", "w", stdout);
    for (int a = 1; a <= 100; a++)
    {
        for (int b = a; b <= 100; b++)
            for (int c = b; c <= 100; c++)
            {
                int res = a * a + b * b + c * c;
                if (gcd(a, res) == 1 && isSquare(res))
                    std::cout << a << ' ' << b << ' ' << c << ' ' << int(sqrt(res)) << '\n';
            }
    }
    return 0;
}
#endif