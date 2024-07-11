#include <bits/stdc++.h>
using namespace std;

void pt(int n)
{
    int temp = sqrt(n);
    for (int i = 2; i <= temp; i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
            temp = sqrt(n);
        }
        if (count > 0)
        {
            if (count == 1)
                std::cout << i;
            else
                std::cout << i << '^' << count;
            if (n > 1)
                std::cout << " * ";
        }
    }
    if (n > 1)
        cout << n << std::flush;
}
int main()
{
    int n;
    cin >> n;
    pt(n);
    return 0;
}