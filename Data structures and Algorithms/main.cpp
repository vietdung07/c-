#include <iostream>
#include <algorithm>
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList<int> list = {88, 18, 100, 92, 98, 49, 30, 72, 93, 94, 97, 12, 49};
    for (auto i : list)
        cout << i << ' ';
    cout << endl;
    list.sort();
    // list.reverse();
    for (auto i : list)
        cout << i << ' ';
    // 85,50,51,54,25,48,4,88,95,64,57,98
    return 0;
}