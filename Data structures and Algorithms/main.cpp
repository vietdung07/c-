#include <iostream>
#include <algorithm>
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList<int> list = {85, 50, 51, 54, 25, 48, 4, 88, 95, 64, 57, 98};
    list.sort();
    list.reverse();
    for (auto i : list)
        cout << i << ' ';
    // 85,50,51,54,25,48,4,88,95,64,57,98
    return 0;
}