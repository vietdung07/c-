#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int tmin = 0, tmax = 0, profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[tmin] > prices[i])
                tmin = i;
            else if (prices[tmax] < prices[i])
                tmax = i;
            if (tmin > tmax)
                tmax = tmin;
            int tmp = 0;
            if (tmax < tmin)
                tmp = prices[tmin] - prices[tmax];
            else if (tmax > tmin)
                tmp = prices[tmax] - prices[tmin];
            profit = max(profit, tmp);
        }
        return profit;
    }
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *tmp = head;
    while (tmp->next != nullptr)
    {
        while (tmp->val == tmp->next->val)
        {
            if (tmp->next == nullptr)
                break;
            tmp = tmp->next;
        }
        tmp = tmp->next;
    }
    return head;
}
int fibonacci(int n)
{
    int n1 = 1, n2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int tmp = n2;
        n2 = n1 + n2;
        n1 = tmp;
    }
    return n2;
}
class Solution1
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> tmp;
        for (int i = 0; i < m; i++)
            tmp.push_back(nums1[m]);
        int i = 0, j = 0;
        int k = 0;
        while (i < tmp.size() && j < nums2.size())
        {
            if (tmp[i] < nums2[j])
            {
                nums1[k] = tmp[i];
                i++;
            }
            else
            {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < nums1.size())
        {
            nums1[k] = tmp[i];
            i++;
            k++;
        }
        while (j < nums1.size())
        {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};
class Solution2
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> k;
        k.push_back({1, 1});
        int row = 1;
        for (int i = 1; i < 5; i++)
        {
            k.push_back({1});
            for (int j = 0; j < k[i - 1].size() - 1; j++)
            {
                k[i].push_back(k[i - 1][j] + k[i - 1][j + 1]);
            }
            k[i].push_back(1);
        }
        return k;
    }
};
class Solution3
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 1)
            return {1};
        else if (rowIndex == 2)
            return {1, 1};
        vector<int> k = {1, 1};
        for (int i = 1; i < rowIndex - 1; i++)
        {
            vector<int> tmp = {1};
            for (int j = 0; j < k.size() - 1; j++)
                tmp.push_back(k[j] + k[j + 1]);
            tmp.push_back(1);
            k = tmp;
        }
        return k;
    }
};
class Solution4
{
public:
    vector<string> summaryRanges(vector<long> &nums)
    {
        vector<string> k;
        int f = 0, l = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums.size() == 0)
                return {};
            if (nums[i] - nums[i - 1] == 1)
                l = i;
            else
            {
                if (f == l)
                    k.push_back(to_string(nums[f]));
                else
                    k.push_back(to_string(nums[f]) + "->" + to_string(nums[l]));
                f = i;
                l = i;
            }
        }
        if (f == l)
            k.push_back(to_string(nums[f]));
        else
            k.push_back(to_string(nums[f]) + "->" + to_string(nums[l]));
        return k;
    }
};
void printL(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << ' ';
        head = head->next;
    }
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution5
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        else if (head->next == nullptr)
            if (head->val == val)
                return nullptr;
            else
                return head;
        ListNode *tmp = head;
        ListNode haha(0);
        ListNode *pre = &haha;
        pre->next = tmp;
        while (tmp != nullptr)
        {
            if (tmp->val == val)
            {
                if (tmp == head)
                {
                    ListNode *t = head;
                    head = head->next;
                    tmp = head;
                    t = nullptr;
                    pre->next = tmp;
                }
                else
                {
                    ListNode *t = tmp;
                    tmp = tmp->next;
                    t = nullptr;
                    pre->next = tmp;
                }
            }
            else
            {
                pre = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};
class Solution6
{
public:
    ListNode *reverseList(ListNode *head)
    {
        vector<ListNode *> k;
        {
            ListNode *tmp = head;
            while (tmp != nullptr)
            {
                k.push_back(tmp);
                tmp = tmp->next;
            }
        }
        for (int i = 0; i < k.size() / 2; i++)
            swap(k[i]->val, k[k.size() - 1 - i]->val);
        return head;
    }
};
int add(int a, int b)
{
    return a + b;
}
int (*getAddFunction())(int, int)
{
    return add;
}
int main()
{
    int (*addFunction)(int, int) = getAddFunction();
    int result = addFunction(3, 4);
    // Output: 7
    return 0;
}

class Solution7
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int f = 0;
        int i = 0;
        for (; i < nums.size(); i++)
            if (nums[i] == 0)
            {
                f = i;
                break;
            }
        for (; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[f]);
                f++;
            }
        }
    }
};