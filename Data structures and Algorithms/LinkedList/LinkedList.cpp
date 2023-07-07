#include <iostream>
#include <typeinfo>
#include <exception>
#include <vector>
using namespace std;
template <typename T>
class NODE;
template <typename T1>
class LinkedList;

template <typename T>
class NODE
{
private:
    NODE<T> *pre;
    NODE<T> *nxt;

public:
    T data;
    NODE() : pre(nullptr), nxt(nullptr) {}
    NODE(T _data) : data(_data), pre(nullptr), nxt(nullptr) {}
    NODE(const NODE &other) = default;
    friend class LinkedList<T>;
};

template <typename T1>
class LinkedList
{
private:
    NODE<T1> *head;
    NODE<T1> *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    LinkedList(const LinkedList<T1> &other) : head(nullptr), tail(nullptr), size(0)
    {
        NODE<T1> *temp = other.head;
        while (temp != nullptr)
        {
            insert(temp->data, size);
            temp = temp->nxt;
        }
    }
    LinkedList(std::initializer_list<T1> args) : head(nullptr), tail(nullptr), size(0)
    {
        for (const T1 &i : args)
            this->insert(i, this->size);
    }
    class iterator
    {
    private:
        NODE<T1> *k;

    public:
        iterator() : k(nullptr) {}
        iterator(NODE<T1> *node) : k(node) {}
        iterator(const iterator &k) = default;
        T1 &operator*() { return k->data; }
        iterator &operator++()
        {
            k = k->nxt;
            return *this;
        }
        bool operator!=(const iterator &other) { return k != other.k; }
    };
    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(); }
    void push_back(T1 data) { insert(data, size); }
    void pop_back() { remove(size - 1); }
    void insert(T1 _data, int index = 0)
    {
        try
        {
            if (index < 0 && index > size)
                throw std::out_of_range("Invalid index");
            NODE<T1> *newNODE = new NODE<T1>(_data);
            if (index == 0 && head == nullptr)
            {
                head = newNODE;
                tail = newNODE;
                size++;
            }
            else
            {
                if (index >= 0 && index <= size)
                {
                    if (index == 0 || index == size)
                    {
                        if (index == 0)
                        {
                            newNODE->nxt = head;
                            head->pre = newNODE;
                            head = newNODE;
                        }
                        else if (index == size)
                        {
                            newNODE->pre = tail;
                            tail->nxt = newNODE;
                            tail = newNODE;
                        }
                    }
                    else
                    {
                        NODE<T1> *before = head;
                        for (int i = 1; i < index; i++)
                        {
                            before = before->nxt;
                        }
                        NODE<T1> *after = before->nxt;
                        before->nxt = newNODE;
                        newNODE->pre = before;
                        newNODE->nxt = after;
                        after->pre = newNODE;
                    }
                }
                size++;
            }
        }
        catch (out_of_range &k)
        {
            cout << "\nInvalid index\n";
            exit(1);
        }
    }
    void remove(int index = 0)
    {
        try
        {
            if (index < 0 && index >= size)
                throw std::out_of_range("Invalid index");
            if (index == 0)
            {
                NODE<T1> *temp = head;
                head = head->nxt;
                head->pre = nullptr;
                delete temp;
                size--;
            }
            else if (index == size - 1)
            {
                NODE<T1> *temp = tail;
                tail = tail->pre;
                tail->nxt = nullptr;
                delete temp;
                size--;
            }
            else
            {
                NODE<T1> *before = head;
                for (int i = 1; i < index; i++)
                {
                    before = before->nxt;
                }
                NODE<T1> *temp = before->nxt;
                NODE<T1> *after = temp->nxt;
                before->nxt = after;
                after->pre = before;
                delete temp;
                size--;
            }
        }
        catch (out_of_range &k)
        {
            cout << "\nInvalid index\n";
            exit(1);
        }
    }
    void clearAll()
    {
        NODE<T1> *cur = head;
        while (cur != nullptr)
        {
            NODE<T1> *temp = cur;
            cur = cur->nxt;
            delete temp;
        }
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    bool isEmpty() { return size == 0; }
    const int &get_size() const { return size; }
    T1 &operator[](int index) const
    {
        try
        {
            if (index >= 0 && index < size)
            {
                NODE<T1> *cur;
                if (index <= size / 2)
                {
                    cur = head;
                    for (int i = 0; i < index; i++)
                        cur = cur->nxt;
                }
                else
                {
                    cur = tail;
                    for (int i = size - 1; i > index; i--)
                        cur = cur->pre;
                }
                return cur->data;
            }
            else
                throw std::out_of_range("Invalid index");
        }
        catch (out_of_range &k)
        {
            cout << "\nInvalid index\n";
            exit(1);
        }
    }
    LinkedList<T1> operator+(const LinkedList<T1> other)
    {
        LinkedList<T1> newone;
        this->tail->nxt = other.head;
        NODE<T1> *temp = this->head;
        while (temp != nullptr)
        {
            newone.insert(temp->data, newone.size);
            temp = temp->nxt;
        }
        this->tail->nxt = nullptr;
        return newone;
    }
    LinkedList<T1> operator+(const NODE<T1> &other)
    {
        LinkedList<T1> newone;
        newone = *this;
        newone.insert(other.data, newone.size);
        return newone;
    }
    LinkedList<T1> &operator=(LinkedList<T1> other)
    {
        NODE<T1> *cur = head;
        while (cur != nullptr)
        {
            NODE<T1> *temp = cur;
            cur = cur->nxt;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
        NODE<T1> *temp = other.head;
        while (temp != nullptr)
        {
            insert(temp->data, size);
            temp = temp->nxt;
        }
        return *this;
    }
    LinkedList<T1> &operator+=(LinkedList<T1> other)
    {
        *this = *this + other;
        return *this;
    }
    LinkedList<T1> &operator+=(NODE<T1> &other)
    {
        *this = *this + other;
        return *this;
    }
    ~LinkedList()
    {
        NODE<T1> *cur = head;
        while (cur != nullptr)
        {
            NODE<T1> *temp = cur;
            cur = cur->nxt;
            delete temp;
        }
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
};
int main()
{
    LinkedList<int> k = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    NODE<int> tmp(100);
    k = k + tmp;
    for (int &i : k)
        cout << i << ' ';
    return 0;
}
