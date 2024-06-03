#include <iostream>
#include <algorithm>
#include "LinkedList.hpp"
using namespace std;
int main()
{
    LinkedList<int> list = {88, 18, 100, 92, 98, 49, 30, 72, 93, 94, 97, 12, 1};
    // list.sort();
    LinkedList<int>::iterator temp = list.begin();
    list.sort();
    std::cout << std::endl;
    return 0;
}