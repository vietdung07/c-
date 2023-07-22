#ifndef LINKED_LIST
#include <iostream>
#include "LinkedList_declaration.h"
template <typename T>
NODE<T>::NODE() : pre(nullptr), nxt(nullptr) {}

template <typename T>
NODE<T>::NODE(T _data) : data(_data), pre(nullptr), nxt(nullptr) {}

template <typename T>
NODE<T>::NODE(const NODE &) = default;
template <typename T1>
LinkedList<T1>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T1>
LinkedList<T1>::LinkedList(const LinkedList<T1> &other) : head(nullptr), tail(nullptr), size(0)
{
    NODE<T1> *temp = other.head;
    while (temp != nullptr)
    {
        insert(temp->data, size);
        temp = temp->nxt;
    }
}

template <class T1>
LinkedList<T1>::LinkedList(std::initializer_list<T1> args) : head(nullptr), tail(nullptr), size(0)
{
    for (const T1 &i : args)
        this->insert(i, this->size);
}

template <class T1>
LinkedList<T1>::iterator::iterator() : k(nullptr) {}

template <class T1>
LinkedList<T1>::iterator::iterator(NODE<T1> *node) : k(node) {}

template <class T1>
LinkedList<T1>::iterator::iterator(const iterator &k) = default;

template <class T1>
T1 &LinkedList<T1>::iterator::operator*() { return k->data; }

template <class T1>
typename LinkedList<T1>::iterator &LinkedList<T1>::iterator::operator++()
{
    k = k->nxt;
    return *this;
}

template <typename T1>
bool LinkedList<T1>::iterator::operator!=(const iterator &other)
{
    return k != other.k;
}

template <typename T1>
typename LinkedList<T1>::iterator LinkedList<T1>::begin() const { return iterator(head); }

template <typename T1>
typename LinkedList<T1>::iterator LinkedList<T1>::end() const { return iterator(); }

template <typename T1>
void LinkedList<T1>::push_back(T1 data) { insert(data, size); }

template <typename T1>
void LinkedList<T1>::pop_back() { remove(size - 1); }

template <typename T1>
void LinkedList<T1>::insert(T1 _data, int index)
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
    catch (...)
    {
        std::cout << "\nInvalid index\n";
        exit(1);
    }
}

template <typename T1>
void LinkedList<T1>::remove(int index)
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
    catch (...)
    {
        std::cout << "\nInvalid index\n";
        exit(1);
    }
}

template <typename T1>
void LinkedList<T1>::clearAll()
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

template <typename T1>
bool LinkedList<T1>::isEmpty() { return size == 0; }

template <typename T1>
const int &LinkedList<T1>::get_size() const { return size; }

template <typename T1>
T1 &LinkedList<T1>::operator[](int index) const
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
    catch (...)
    {
        std::cout << "\nInvalid index\n";
        exit(1);
    }
}

template <typename T1>
LinkedList<T1> LinkedList<T1>::operator+(const LinkedList<T1> other)
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

template <typename T1>
LinkedList<T1> LinkedList<T1>::operator+(const NODE<T1> &other)
{
    LinkedList<T1> newone;
    newone = *this;
    newone.insert(other.data, newone.size);
    return newone;
}

template <typename T1>
LinkedList<T1> &LinkedList<T1>::operator=(LinkedList<T1> other)
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

template <typename T1>
LinkedList<T1> &LinkedList<T1>::operator+=(LinkedList<T1> other)
{
    *this = *this + other;
    return *this;
}

template <typename T1>
LinkedList<T1> &LinkedList<T1>::operator+=(NODE<T1> &other)
{
    *this = *this + other;
    return *this;
}

template <typename T1>
LinkedList<T1>::~LinkedList()
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
#endif // !LINKED_LIST