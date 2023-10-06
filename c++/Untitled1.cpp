#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
unsigned long long to_hop(int k, int n)
{
     if (k > n || n < 0 || k < 0)
          return 0;
     else if (k == 0 || k == n)
          return 1;
     else if (k == 1)
          return n;
     stack<pair<int, int>> callStack;
     callStack.push({k, n});
     // cout << callStack.top().first << ' ' << callStack.top().second << endl;
     int sum = 0;

     while (!callStack.empty())
     {
          pair<int, int> tmp = callStack.top();
          callStack.pop();
          // cout << callStack.top().first << ' ' << callStack.top().second << endl;
          if (tmp.second == tmp.first + 1 && tmp.first > 2)
               sum += 1;

          if ((tmp.first > 2 && tmp.first < tmp.second - 1))
          {
               callStack.push({tmp.first, tmp.second - 1});
               // cout << callStack.top().first << ' ' << callStack.top().second << endl;
          }

          callStack.push({tmp.first - 1, tmp.second - 1});
          // cout << callStack.top().first << ' ' << callStack.top().second << endl;
          if (callStack.top().first == 1)
          {
               sum += callStack.top().second;
               // cout << sum << '\n';
               // callStack.pop();
               pair<int, int> t = callStack.top();
               callStack.pop();
               // cout << callStack.top().first << ' ' << callStack.top().second << endl;
               callStack.push({t.first + 1, t.second});
               // cout << callStack.top().first << ' ' << callStack.top().second << endl;
               if (callStack.top().first == callStack.top().second)
               {
                    sum += 1;
                    // cout << sum << '\n';
                    callStack.pop();
                    // cout << callStack.top().first << ' ' << callStack.top().second << endl;
               }
          }
     }

     return sum;
}

unsigned long long to_hop_2(int k, int n)
{
     static long long arr[101][101];
     static bool flag = true;
     if (flag)
     {
          flag = false;
          for (int i = 0; i < 101; i++)
          {
               arr[i][i] = 1;
               arr[0][i] = 1;
          }
          for (int i = 1; i <= 100; i++)
               for (int j = 1; j <= i; j++)
                    arr[j][i] = arr[j - 1][i - 1] + arr[j][i - 1];
     }
     return arr[k][n];
}

int main()
{
     cout << to_hop_2(2, 10);
     return 0;
}