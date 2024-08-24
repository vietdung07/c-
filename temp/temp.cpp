#include <iostream>
#if 0
bool bino_co_array[10];
int Main_arr[6];
bool sub_arr[6];
int temp[6];
int n = 6;
int cur = 0;
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
    if (n == k)
    {
        permute(0);
    }
    else
    {
        int temp = cur;
        for (int i = temp; i < 10; i++)
        {
            bino_co_array[i] = true;
            Main_arr[k] = i;
            cur = i + 1;
            binomial_coefficient_gen(k + 1);
            bino_co_array[i] = false;
        }
    }
}
int main()
{
    freopen("main.out", "w", stdout);
    binomial_coefficient_gen(0);
    std::cout << count;
    return 0;
}
#endif
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