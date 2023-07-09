#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList<int> list = {1, 2, 3, 4, 5, 6};
    for (int &i : list)
        cout << i << ' ';
    return 0;
}