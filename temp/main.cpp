#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#if 1
vector<vector<int>> sum(int begin, int last)
{
    if (last == 0 || begin > last)
    {
        return vector<vector<int>>();
    }
    vector<vector<int>> ans;
    for (int i = begin; i <= last; i++)
    {
        for (vector<int> &track : sum(i, last - i))
        {
            ans.push_back(vector<int>{i});
            ans[ans.size() - 1].insert(ans[ans.size() - 1].end(), track.begin(), track.end());
        }
    }
    ans.push_back(vector<int>{last});
    return ans;
}
#endif
#if 0
bool check(int n)
{
    int count = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if (count > 1)
                return false;
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1 && count > 0)
        return false;
    return true;
}
#endif
#if 0
int main()
{
    // // sieve_prime
    freopen("main.out", "w", stdout);
    char a[1000003] = {0};
    int n = 1000000;
    // queue<pair<int, int>> temp;
    for (int i = 2; i * i <= n; i++)
        if (!a[i])
            for (int j = i * i; j <= n; j += i)
                a[j] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i] == 0)
        {
            for (long long j = (long long)i * i, count = 2; j <= (long long)n; j *= (long long)i * i, count += 2)
                if (a[count + 1] == 0)
                    a[j] = 2;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 2 || a[i] == 0)
            cout << i << ' ' << (int)a[i] << '\n'
                 << flush;
    }
    return 0;
}
#endif
#if 0
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

void permute(vector<int> &a, int n)
{
    while (true)
    {
        print(a);
        int k, l;
        for (k = n - 2; k >= 0; k--)
            if (a[k] < a[k + 1])
                break; // Bước 1
        if (k < 0)
            break; //
        for (l = n - 1; l > k; l--)
            if (a[k] < a[l])
                break;    // Bước 2
        swap(a[k], a[l]); // Bước 3
        for (int i = k + 1, j = n - 1; i < j; i++, j--)
            swap(a[i], a[j]); // Bước 4
    }
}

int main()
{
    freopen("main.out", "w", stdout);
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    permute(a, a.size());
    return 0;
}
#endif
#if 0
int main()
{
    freopen("main.out", "w", stdout);
    int a[250001] = {0};
    int s;
    cin >> s;
    for (int k = 2; k <= s; k++)
    {
        int temp = k;
        for (int i = 2; i * i <= temp; i++)
        {
            if (temp % i == 0)
            {
                while (temp % i == 0)
                {
                    a[i]++;
                    temp /= i;
                }
            }
        }
        if (temp > 1)
            a[temp]++;
    }

    for (int i = 2; i <= s; i++)
    {
        if (a[i] > 0)
            cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
#endif
#if 0

long long sum_square(long long n, long long modulo)
{
    long long a = n, b = n + 1, c = 2 * n + 1;
    if (a % 2 == 0)
        a /= 2;
    else if (b % 2 == 0)
        b /= 2;
    else if (c % 2 == 0)
        c /= 2;

    if (a % 3 == 0)
        a /= 3;
    else if (b % 3 == 0)
        b /= 3;
    else if (c % 3 == 0)
        c /= 3;

    a %= modulo;
    b %= modulo;
    c %= modulo;

    long long kq = a;
    kq = (kq * b) % modulo;
    kq = (kq * c) % modulo;
    return kq;
}

int main()
{
    long long a, b, m;
    std::cin >> a >> b >> m;
    long long res = sum_square(b, m) - sum_square(a - 1, m);
    if (res < 0)
        res += m;
    std::cout << res << std::endl;
    return 0;
}
#endif // 1