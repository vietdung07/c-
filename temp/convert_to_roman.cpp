
#if 0
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string lineEncoding(string s)
{
    int i = 0;
    int count = 1;
    string res = "";
    while (i < s.size())
    {
        while (i + 1 < s.size())
        {
            if (s[i] == s[i + 1])
            {
                count++;
                i++;
            }
            else
                break;
        }

        if (count <= 1)
            res += s[i];
        else
            res += to_string(count) + string({s[i]});

        count = 1;
        i++;
    }
    return res;
}
int x, y;
void extended_euclidean(int a, int b)
{
    if (a == 0)
    {
        if (b == 1)
        {
            x = 0;
            y = 1;
        }
        else
        {
            std::cout << "No solution" << std::endl;
            return;
        }
    }
    else
    {
        extended_euclidean(b % a, a);
        int temp = x;
        x = y - (b / a) * x;
        y = temp;
    }
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    extended_euclidean(a, b);
    if (x < 0)
        x += b;
    std::cout << x << std::endl;
    return 0;
}
#endif
#if 1
#include <iostream>
#include <utility>
#include <stack>
using namespace std;
unsigned long long combination(int k, int n)
{
    if (k > n || n < 0 || k < 0)
        return 0;
    else if (k == 0 || k == n)
        return 1;
    else if (k == 1)
        return n;
    stack<pair<int, int>> callStack;
    callStack.push({k, n});
    unsigned long long sum = 0;

    while (!callStack.empty())
    {
        pair<int, int> tmp = callStack.top();
        callStack.pop();
        if (tmp.second == tmp.first + 1 && tmp.first > 2)
            ++sum;

        if ((tmp.first > 2 && tmp.first < tmp.second - 1))
        {
            callStack.push({tmp.first, tmp.second - 1});
        }

        callStack.push({tmp.first - 1, tmp.second - 1});
        if (callStack.top().first == 1)
        {
            sum += callStack.top().second;
            pair<int, int> t = callStack.top();
            callStack.pop();
            callStack.push({t.first + 1, t.second});
            if (callStack.top().first == callStack.top().second)
            {
                ++sum;
                callStack.pop();
            }
        }
    }

    return sum;
}
int main()
{
    int n, k;
    cin >> k >> n;
    cout << combination(k, n);
    return 0;
}
#endif
