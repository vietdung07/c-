#if 1
#include <iostream>
#include <algorithm>
#include <cassert>
#include <ctime>
#include "LinkedList.hpp"
using namespace std;
void test_empty_linked_list()
{
    LinkedList<int> list;
    assert(list.isEmpty());
    assert(list.get_size() == 0);
    assert(!(list.begin() != list.end()));
    assert(!(list.r_begin() != list.r_end()));
}

void test_push_back()
{
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    assert(!list.isEmpty());
    assert(list.get_size() == 3);

    // Check elements using iterators
    auto it = list.begin();
    assert(*it == 1);
    ++it;
    assert(*it == 2);
    ++it;
    assert(*it == 3);
    ++it;
    assert(!(it != list.end()));

    // Check elements using operator[]
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);
}

void test_pop_back()
{
    LinkedList<int> list = {1, 2, 3};
    list.pop_back();
    assert(list.get_size() == 2);
    assert(list[0] == 1);
    assert(list[1] == 2);

    list.pop_back();
    assert(list.get_size() == 1);
    assert(list[0] == 1);

    list.pop_back();
    assert(list.get_size() == 0);
    assert(list.isEmpty());
}

void test_insert()
{
    LinkedList<int> list = {1, 2, 4};

    // Insert at the beginning
    list.insert(3, 0);
    assert(list.get_size() == 4);
    assert(list[0] == 3);
    assert(list[1] == 1);
    assert(list[2] == 2);
    assert(list[3] == 4);

    // Insert in the middle
    list.insert(5, 2);
    assert(list.get_size() == 5);
    assert(list[0] == 3);
    assert(list[1] == 1);
    assert(list[2] == 5);
    assert(list[3] == 2);
    assert(list[4] == 4);

    // Insert at the end
    list.insert(6, list.get_size());
    assert(list.get_size() == 6);
    assert(list[0] == 3);
    assert(list[1] == 1);
    assert(list[2] == 5);
    assert(list[3] == 2);
    assert(list[4] == 4);
    assert(list[5] == 6);
}

void test_remove()
{
    LinkedList<int> list = {1, 2, 3, 4, 5};

    // Remove from the beginning
    list.remove(0);
    assert(list.get_size() == 4);
    assert(list[0] == 2);
    assert(list[1] == 3);
    assert(list[2] == 4);
    assert(list[3] == 5);

    // Remove from the middle
    list.remove(2);
    assert(list.get_size() == 3);
    assert(list[0] == 2);
    assert(list[1] == 3);
    assert(list[2] == 5);

    // Remove from the end
    list.remove(2);
    assert(list.get_size() == 2);
    assert(list[0] == 2);
    assert(list[1] == 3);
}

void test_clearAll()
{
    LinkedList<int> list = {1, 2, 3, 4, 5};
    list.clearAll();
    assert(list.isEmpty());
    assert(list.get_size() == 0);
}

void test_reverse()
{
    LinkedList<int> list = {1, 2, 3, 4, 5};
    list.reverse();
    assert(list[0] == 5);
    assert(list[1] == 4);
    assert(list[2] == 3);
    assert(list[3] == 2);
    assert(list[4] == 1);
}

void test_sort()
{
    LinkedList<int> list = {5, 2, 4, 1, 3};
    list.sort();
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);
    assert(list[3] == 4);
    assert(list[4] == 5);
}

void test_operator_plus()
{
    LinkedList<int> list1 = {1, 2, 3};
    LinkedList<int> list2 = {4, 5, 6};
    LinkedList<int> list3 = list1 + list2;
    assert(list3.get_size() == 6);
    assert(list3[0] == 1);
    assert(list3[1] == 2);
    assert(list3[2] == 3);
    assert(list3[3] == 4);
    assert(list3[4] == 5);
    assert(list3[5] == 6);

    // Test adding a node
    NODE<int> node(7);
    LinkedList<int> list4 = list1 + node;
    assert(list4.get_size() == 4);
    assert(list4[0] == 1);
    assert(list4[1] == 2);
    assert(list4[2] == 3);
    assert(list4[3] == 7);
}

void test_operator_assignment()
{
    LinkedList<int> list1 = {1, 2, 3};
    LinkedList<int> list2 = {4, 5, 6};
    LinkedList<int> list3 = list1;
    assert(list3.get_size() == 3);
    assert(list3[0] == 1);
    assert(list3[1] == 2);
    assert(list3[2] == 3);
    list3 = list2;
    assert(list3.get_size() == 3);
    assert(list3[0] == 4);
    assert(list3[1] == 5);
    assert(list3[2] == 6);

    // Test move assignment
    LinkedList<int> list4 = {7, 8, 9};
    list3 = std::move(list4);
    assert(list4.get_size() == 0);
    assert(list3.get_size() == 3);
    assert(list3[0] == 7);
    assert(list3[1] == 8);
    assert(list3[2] == 9);
}

void test_operator_plus_equals()
{
    LinkedList<int> list1 = {1, 2, 3};
    LinkedList<int> list2 = {4, 5, 6};
    list1 += list2;
    assert(list1.get_size() == 6);
    assert(list1[0] == 1);
    assert(list1[1] == 2);
    assert(list1[2] == 3);
    assert(list1[3] == 4);
    assert(list1[4] == 5);
    assert(list1[5] == 6);

    // Test move assignment
    LinkedList<int> list3 = {7, 8, 9};
    list1 += std::move(list3);
    assert(list3.get_size() == 0);
    assert(list1.get_size() == 9);
    assert(list1[6] == 7);
    assert(list1[7] == 8);
    assert(list1[8] == 9);

    // Test adding a node
    NODE<int> node(10);
    list1 += node;
    assert(list1.get_size() == 10);
    assert(list1[9] == 10);
}

int main()
{
    clock_t start = clock(), end;
    // test_empty_linked_list();
    // test_push_back();
    // test_pop_back();
    // test_insert();
    // test_remove();
    // test_clearAll();
    // test_reverse();
    // test_sort();
    // test_operator_plus();
    // test_operator_assignment();
    // test_operator_plus_equals();
    // cout << "All tests passed!" << endl;

    LinkedList<int> temp = {83, 41, 53, 40, 56, 64, 45, 20, 44, 100, 26, 61, 84, 65};
    std::cout << temp.get_size() << std::endl;
    temp.sort();
    for (auto &i : temp)
        std::cout << i << ' ';
    end = clock();
    std::cout << "\nRuntime : " << (double)(end - start) / 1000 << " second\n"
              << std::flush;
    // system("timeout /t 5 /nobreak");
    // system("exit");
    return 0;
}
#endif