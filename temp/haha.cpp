
#if 0
#include <iostream>
int main()
{
    int N, K, T;
    std::cin >> T;

    while (T--)
    {
        std::cin >> N >> K;
        int pow = K;
        int sum = 0;
        while (pow <= N)
        {
            sum += N / pow;
            pow *= K;
        }
        std::cout << sum << std ::endl;
    }
    return 0;
}
#endif

#if 0
#include <iostream>
int a[1000000];
bool check[1000000];
int main()
{
    // freopen("main.out", "w", stdout);
    int m, n;
    std::cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        int temp = i;
        for (int j = 2; j * j <= temp; j++)
        {
            if (temp % j == 0)
            {
                int count = 0;
                while (temp % j == 0)
                {
                    count++;
                    temp /= j;
                }
                a[j] += count;
            }
        }
        if (temp > 1)
            a[temp]++;
    }
    unsigned long long res = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > 0)
        {
            // std::cout << i;
            // if (a[i] > 1)
            //     std::cout << '^' << a[i];
            // std::cout << ' ';
            res *= (2 * a[i] + 1);
        }
    }
    std::cout << res << std::endl;
    return 0;
}

#endif

#if 0
#include <iostream>
#include <cmath>
int main()
{
    int n;
    std::cin >> n;
    int temp = sqrt(2 * n);
    if (temp * (temp + 1) == 2 * n)
        std::cout << "Yes";
    else
        std::cout << "NO";
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
int a[10];
void Try(int k)
{
    for (int i = 0; i <= 2; i++)
    {
        
    }
}
int main()
{

    return 0;
}
#endif