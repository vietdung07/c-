#if 1
#include <iostream>
#define MAX 25
#define RES 4
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
        int x = Main_arr[0];
        int y = Main_arr[1];
        int z = Main_arr[2];
        int t = Main_arr[3];
        if (/* x + t == y + z  ||*/ z + t == x + y + 24)
        {
            std::cout << x << ' ' << y << ' ' << z << ' ' << t << '\n';
            count++;
        }
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