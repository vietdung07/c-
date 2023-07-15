#include <iostream>
#include <cmath>
#include <typeinfo>
#include <sstream>
#include <string>
using namespace std;
int add_digit(int a, int b)
{
    int count = 0;
    int tmpb = b;
    while (tmpb > 0)
    {
        count++;
        tmpb /= 10;
    }
    return (a * static_cast<int>(pow(10.0f, static_cast<float>(count))) + b) * 10 + count;
}
namespace temp
{
    int Qpart(int arr[], const int begin, const int end)
    {
        int count = 0;
        int i = begin, j = end;
        const int mid = (begin + end) / 2;
        int pivot = mid;
        {
            count++;
            int max = begin, min = begin;
            if (arr[max] < arr[mid])
                max = mid;
            if (arr[max] < arr[end])
                max = end;
            if (arr[min] > arr[mid])
                min = mid;
            if (arr[min] > arr[end])
                min = end;
            if (arr[end] < arr[max] && arr[end] > arr[min])
                pivot = end;
            else if (arr[begin] < arr[max] && arr[begin] > arr[min])
                pivot = begin;
        }
        while (i != pivot || j != pivot)
        {
            count++;
            if (arr[i] <= arr[pivot] && i < pivot)
                i++;
            if (arr[j] >= arr[pivot] && j > pivot)
                j--;
            if (arr[i] >= arr[pivot] && arr[pivot] >= arr[j])
            {
                swap(arr[i], arr[j]);
                if (i == pivot)
                    pivot = j;
                else if (j == pivot)
                    pivot = i;
            }
        }
        return add_digit(count, pivot);
    }
    int merge(int arr[], int begin, int mid, int end)
    {
        int count = 0;
        const int size1 = mid - begin + 1;
        const int size2 = end - mid;
        int *arr1 = new int[size1];
        int *arr2 = new int[size2];
        for (int i = 0; i < size1; i++)
        {
            count++;
            arr1[i] = arr[begin + i];
        }
        for (int i = 0; i < size2; i++)
        {
            count++;
            arr2[i] = arr[mid + 1 + i];
        }
        int index_1 = 0, index_2 = 0;
        int index = begin;
        while (index_1 < size1 && index_2 < size2)
        {
            count++;
            if (arr1[index_1] < arr2[index_2])
            {
                arr[index] = arr1[index_1];
                index_1++;
            }
            else
            {
                arr[index] = arr2[index_2];
                index_2++;
            }
            index++;
        }
        while (index_1 < size1)
        {
            count++;
            arr[index] = arr1[index_1];
            index++;
            index_1++;
        }
        while (index_2 < size2)
        {
            count++;
            arr[index] = arr2[index_2];
            index++;
            index_2++;
        }
        delete[] arr1;
        delete[] arr2;
        return count;
    }
} // namespace temp
namespace sorting
{
    void Quick_sort(int arr[], int begin, int end)
    {
        static int count = 0;
        if (begin >= end)
            return;
        int tmp = temp::Qpart(arr, begin, end);
        int mod = static_cast<int>(pow(10.0f, static_cast<float>(tmp % 10 + 1)));
        count += tmp / mod;
        int pivot = (tmp % mod) / 10;
        Quick_sort(arr, begin, pivot - 1);
        Quick_sort(arr, pivot + 1, end);
        cout << count << endl;
    }
    int Merge_sort(int arr[], int begin, int end)
    {
        int count = 0;
        if (begin >= end)
            return count;
        int mid = (begin + end) / 2;
        Merge_sort(arr, begin, mid);
        Merge_sort(arr, mid + 1, end);
        count += temp::merge(arr, begin, mid, end);
        return count;
    }
    void Bubble_sort(int arr[], int size)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            count++;
            for (int j = 0; j < size - 1; j++)
            {
                count++;
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }
    void Selection_sort(int arr[], int size)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            count++;
            int min = i;
            for (int j = i + 1; j < size; j++)
            {
                count++;
                if (arr[j] < arr[min])
                    min = j;
            }
            swap(arr[i], arr[min]);
        }
        cout << count << endl;
    }
    void Insertion_sort(int arr[], int size)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            count++;
            int t = 0;
            for (; t < i; t++)
            {
                count++;
                if (arr[t] > arr[i])
                    break;
            }
            if (t < i)
            {
                int temp = arr[i];
                for (int j = i - 1; j >= t; j--)
                {
                    count++;
                    arr[j + 1] = arr[j];
                }
                arr[t] = temp;
            }
        }
        cout << count << endl;
    }
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
}

// 36,15,26,87,65,99,98,19,18,11,65,56,28
// 12,59,67,79,25,80,71,57,18,19,93,81,47
// 66,61,62,100,64,40,97,37,1,22,65,18,12
// 88,18,100,92,98,49,30,72,93,94,97,12,49

int main()
{
    int a[26] = {88, 18, 100, 92, 98, 49, 30, 72, 93, 94, 97, 12, 49, 66, 61, 62, 100, 64, 40, 97, 37, 1, 22, 65, 18, 12};
    sorting::Quick_sort(a, 0, 25);
    printArr(a, 26);
    return 0;
}