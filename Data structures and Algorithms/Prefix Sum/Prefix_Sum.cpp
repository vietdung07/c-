#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1 + 1e5;

int n, a[MaxN], t, s[MaxN];

int main()
{
    freopen("Prefix_Sum.out", "w", stdout);
    freopen("Prefix_Sum.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i];
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        cout << s[y] - s[x - 1] << endl;
    }
    return 0;
}