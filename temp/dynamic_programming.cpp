#if 0
#include <iostream>
#include <vector>
std::vector<bool> &sieve()
{
    static std::vector<bool> non_primes(10001, false);
    non_primes[0] = non_primes[1] = false;
    for (int i = 2; i < 10001; i++)
    {
        if (non_primes[i] == 0)
        {
            for (int j = i * i; j < 10001; j += i)
                non_primes[j] = true;
        }
    }
    return non_primes;
}
int main()
{
    const std::vector<bool> non_primes = sieve();
    int dp[10001][2] = {{0, 0}};
    dp[4][0] = 1;
    dp[4][1] = 4;
    // dp[n]=max{dp[i]}+1|dp[i][1]non-prime,n-inon-prime,dp[i][1]<n-i
    for (int i = 5; i <= 10000; i++)
    {
        int max_0 = 0;
        int max_1 = 0;
        for (int j = 4; j < i; j++)
        {
            if (non_primes[i - j] && dp[j][1] < i - j && dp[j][1] != 0 && max_0 <= dp[j][0])
            {
                max_0 = dp[j][0];
                max_1 = i - j;
            }
        }
        if (!max_0)
            continue;
        dp[i][0] = max_0 + 1;
        dp[i][1] = max_1;
    }
    // freopen("main.out", "w", stdout);
    int temp;
    std::cin >> temp;
    std::cout << dp[temp][0] << '\n';
    std::cout << temp << " = ";
    while (temp >= 4)
    {
        std::cout << dp[temp][1];
        if (temp > 4)
            std::cout << " + ";
        if (temp < 0)
            break;
        if (dp[temp][1] <= 0)
            break;
        temp -= dp[temp][1];
    }
    std::cout << '\n';
    return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
std::vector<bool> &sieve()
{
    static std::vector<bool> non_primes(2026, false);
    non_primes[0] = non_primes[1] = false;
    for (int i = 2; i < 2026; i++)
    {
        if (non_primes[i] == 0)
        {
            for (int j = i * i; j < 2026; j += i)
                non_primes[j] = true;
        }
    }
    return non_primes;
}
const auto non_primes = sieve();
const int n = 150;
const int limit = 3;
bool on_limit = true;
bool on_check_non_primes = false;
int res[100] = {0};
int count = 0;
void Try(int k, int term, int sum)
{
    if (k > limit && on_limit)
        return;
    else if (sum == n && (k == limit || !on_limit))
    {
        if (on_limit)
        {
            // bool flag = true;
            // for (int i = 0; i < k; i++)
            // {
            //     if (res[i] > 100)
            //     {
            //         flag = false;
            //         break;
            //     }
            // }
            // if (flag)
                count++;
        }
        else
        {
            int i = 0;
            int temp = n;
            while (res[i] > 0 && temp > 0)
            {
                std::cout << res[i];
                if (temp - res[i])
                    std::cout << " + ";
                temp -= res[i];
                i++;
            }
            std::cout << "\n";
        }
    }
    else if (sum > n)
        return;
    else
    {
        for (int i = term + 1; i <= n; i++)
        {
            if (non_primes[i] || !on_check_non_primes)
            {
                res[k] = i;
                Try(k + 1, i, sum + i);
            }
        }
    }
}
int main()
{
    freopen("main.out", "w", stdout);
    Try(0, 0, 0);
    std::cout << count;
    return 0;
}
#endif
#if 0
#include <iostream>
#include <iomanip>
float tiendiennuoc(float d)
{
    float sum;
    if (d <= 100)
    {
        sum = 1242 * d;
    }
    else if (100 < d && d <= 150)
    {
        sum = 1242 * 100 + 1369 * (d - 100);
    }
    else if (150 < d && d <= 200)
    {
        sum = 1242 * 100 + 1369 * 50 + 1734 * (d - 150);
    }
    else
        sum = 1242 * 100 + 1369 * 50 + 1734 * 50 + 1877 * (d - 200);
    return sum;
}
int main()
{
    float d;
    std::cin >> d;
    std::cout << std::setprecision(0) << std::fixed << tiendiennuoc(d) << std::endl;
    return 0;
}

#endif
#if 1
#include <iostream>
#include <cmath>
void print_bit(void *n, unsigned long long size)
{
    unsigned long long temp = *(unsigned long long *)n;
    for (int i = 8ULL * size; i >= 0; i--)
    {
        if (temp & (1ULL << i))
            std::cout << '1';
        else
            std::cout << '0';
    }
    std::cout << '\n';
}
struct Point
{
    double x, y, z;
};
struct Vector
{
public:
    double x, y, z;
    Vector() = default;
    Vector(const Vector &) = default;
    Vector(const double &_x, const double &_y, const double &_z) : x(_x), y(_y), z(_z) {}
    Vector(const Point &initial, const Point &terminal) : x(terminal.x - initial.x), y(terminal.y - initial.y), z(terminal.z - initial.z) {}
    Vector operator+(const Vector &other) const
    {
        return Vector(x + other.x, y + other.y, z + other.z);
    }
    Vector operator-(const Vector &other) const
    {
        return Vector(x - other.x, y - other.y, z - other.z);
    }
};
double dotProduct(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Vector crossProduct(const Vector &a, const Vector &b)
{
    Vector res;
    res.x = a.y * b.z - a.z * b.y;
    if (res.x == -0.0)
        res.x = 0.0;
    res.y = a.z * b.x - a.x * b.z;
    if (res.y == -0.0)
        res.y = 0.0;
    res.z = a.x * b.y - a.y * b.x;
    if (res.z == -0.0)
        res.z = 0.0;
    return res;
}
double lengthofVector(const Vector &v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
double areaTriangle(const Point &A, const Point &B, const Point &C)
{
    Vector AB(A, B);
    Vector AC(A, C);
    Vector res(crossProduct(AB, AC));

    return 0.5 * lengthofVector(res);
}
std::ostream &operator<<(std::ostream &os, const Vector &ouput)
{
    os << '(' << ouput.x << ',' << ouput.y << ',' << ouput.z << ')';
    return os;
}
int main()
{
   std::cout<<(-1+26)%26;
    return 0;
}
#endif