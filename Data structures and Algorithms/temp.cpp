#include <iostream>
using namespace std;
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
    NODE();
    NODE(T _data);
    NODE(const NODE &other);
    NODE(NODE &&other);
    friend class LinkedList<T>;
};

template <typename T1>
class LinkedList
{
private:
    NODE<T1> *head;
    NODE<T1> *tail;
    int size;
    class base_iterator;
    class base_iterator
    {
    protected:
        NODE<T1> *k;

    public:
        base_iterator();
        base_iterator(NODE<T1> *node);
        base_iterator(const base_iterator &k);
        T1 &operator*();
        virtual base_iterator &operator++() = 0;
        bool operator!=(const base_iterator &other);
    };

public:
    LinkedList();
    LinkedList(const LinkedList<T1> &other);
    LinkedList(LinkedList<T1> &&other) noexcept;
    LinkedList(std::initializer_list<T1> args);
    class iterator;
    class iterator : public base_iterator
    {
    public:
        iterator() {}
        iterator(NODE<T1> *node) : base_iterator(node) {}
        iterator(const iterator &other) = default;
        iterator &operator++() override;
        bool operator!=(const iterator &other);
    };
    class r_iterator;
    class r_iterator : public base_iterator
    {
    public:
        r_iterator() {}
        r_iterator(NODE<T1> *node) : base_iterator(node) {}
        r_iterator(const r_iterator &other) = default;
        r_iterator &operator++() override;
        bool operator!=(const r_iterator &other);
    };
    iterator begin() const;
    iterator end() const;
    r_iterator r_begin() const;
    r_iterator r_end() const;
    void push_back(T1 data);
    void pop_back();
    void insert(T1 _data, int index = 0);
    void remove(int index = 0);
    void clearAll();
    void sort();
    void reverse();
    bool isEmpty();
    const int get_size() const;
    T1 &operator[](int index) const;
    LinkedList<T1> operator+(const LinkedList<T1> &other) const;
    LinkedList<T1> operator+(const NODE<T1> &other) const;
    LinkedList<T1> &operator=(const LinkedList<T1> &other);
    LinkedList<T1> &operator=(LinkedList<T1> &&other) noexcept;
    LinkedList<T1> &operator+=(const LinkedList<T1> &other);
    LinkedList<T1> &operator+=(const NODE<T1> &other);
    ~LinkedList();
};
template <typename T>
NODE<T>::NODE() : pre(nullptr), nxt(nullptr) {}

template <typename T>
NODE<T>::NODE(T _data) : pre(nullptr), nxt(nullptr), data(_data) {}

template <typename T>
NODE<T>::NODE(const NODE &other) = default;

template <typename T>
NODE<T>::NODE(NODE &&other) = default;

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

template <typename T1>
LinkedList<T1>::LinkedList(LinkedList<T1> &&other) noexcept : head(other.head), tail(other.tail), size(other.size)
{
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
    // cout << "move\n";
}

template <class T1>
LinkedList<T1>::LinkedList(std::initializer_list<T1> args) : head(nullptr), tail(nullptr), size(0)
{
    for (const T1 &i : args)
        this->insert(i, this->size);
}

template <class T1>
LinkedList<T1>::base_iterator::base_iterator() : k(nullptr) {}

template <class T1>
LinkedList<T1>::base_iterator::base_iterator(NODE<T1> *node) : k(node) {}

template <class T1>
LinkedList<T1>::base_iterator::base_iterator(const base_iterator &k) = default;

template <class T1>
T1 &LinkedList<T1>::base_iterator::operator*() { return k->data; }

template <typename T1>
bool LinkedList<T1>::iterator::operator!=(const iterator &other)
{
    return base_iterator::k != other.k;
}

template <typename T1>
bool LinkedList<T1>::r_iterator::operator!=(const r_iterator &other)
{
    return base_iterator::k != other.k;
}

template <typename T1>
typename LinkedList<T1>::iterator &LinkedList<T1>::iterator::operator++()
{
    base_iterator::k = base_iterator::k->nxt;
    return *this;
}

template <typename T1>
typename LinkedList<T1>::r_iterator &LinkedList<T1>::r_iterator::operator++()
{
    base_iterator::k = base_iterator::k->pre;
    return *this;
}

template <typename T1>
typename LinkedList<T1>::iterator LinkedList<T1>::begin() const { return iterator(head); }

template <typename T1>
typename LinkedList<T1>::iterator LinkedList<T1>::end() const { return iterator(); }

template <typename T1>
typename LinkedList<T1>::r_iterator LinkedList<T1>::r_begin() const { return r_iterator(tail); }

template <typename T1>
typename LinkedList<T1>::r_iterator LinkedList<T1>::r_end() const { return r_iterator(); }

template <typename T1>
void LinkedList<T1>::push_back(T1 data) { insert(data, size); }

template <typename T1>
void LinkedList<T1>::pop_back() { remove(size - 1); }

template <typename T1>
void LinkedList<T1>::insert(T1 _data, int index)
{
    try
    {
        if (index < 0 || index > size)
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
        if (index < 0 || index >= size)
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
void LinkedList<T1>::reverse()
{
    NODE<T1> *pre_h = nullptr;
    NODE<T1> *pre_t = nullptr;
    NODE<T1> *nxt_h = this->head;
    NODE<T1> *nxt_t = this->tail;
    while (nxt_h != nullptr)
    {
        NODE<T1> *temp_h = nxt_h;
        NODE<T1> *temp_t = nxt_t;
        nxt_h = nxt_h->nxt;
        nxt_t = nxt_t->pre;
        temp_h->nxt = pre_h;
        temp_t->pre = pre_t;
        pre_h = temp_h;
        pre_t = temp_t;
    }
    NODE<T1> *temp = this->head;
    this->head = this->tail;
    this->tail = temp;
}

// template <typename T1>
// void LinkedList<T1>::sort() const
// {
//     for (LinkedList<T1>::base_iterator i = this->begin(); i != this->end(); ++i)
//     {
//         LinkedList<T1>::base_iterator temp = i;
//         ++temp;
//         LinkedList<T1>::base_iterator min = i;
//         for (LinkedList<T1>::base_iterator u = temp; u != this->end(); ++u)
//         {
//             if ((*min) > (*u))
//                 min = u;
//         }
//         T1 temp1 = *i;
//         *i = *min;
//         *min = temp1;
//     }
// }

template <typename T1>
void LinkedList<T1>::sort()
{
    for (NODE<T1> *i = this->head; i != nullptr; i = i->nxt)
    {
        NODE<T1> *t = this->head;
        for (; t != i; t = t->nxt)
            if (t->data > i->data)
                break;
        if (t != i)
        {
            NODE<T1> *temp = i;
            // isolate
            NODE<T1> *pre_i_temp = temp->pre;
            NODE<T1> *nxt_i_temp = temp->nxt;
            if (i == this->tail)
            {
                pre_i_temp->nxt = nullptr;
                this->tail = pre_i_temp;
                i = pre_i_temp;
            }
            else
            {
                pre_i_temp->nxt = nxt_i_temp;
                nxt_i_temp->pre = pre_i_temp;
                i = pre_i_temp;
            }
            // insert
            if (t == this->head)
            {
                temp->nxt = t;
                t->pre = temp;
                this->head = temp;
                temp->pre = nullptr;
            }
            else
            {
                NODE<T1> *pre_t_temp = t->pre;
                pre_t_temp->nxt = temp;
                temp->pre = pre_t_temp;
                temp->nxt = t;
                t->pre = temp;
            }
        }
    }
}

template <typename T1>
bool LinkedList<T1>::isEmpty() { return size == 0; }

template <typename T1>
const int LinkedList<T1>::get_size() const { return size; }

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
LinkedList<T1> LinkedList<T1>::operator+(const LinkedList<T1> &other) const
{
    if (this->head == nullptr)
        return other;
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
LinkedList<T1> LinkedList<T1>::operator+(const NODE<T1> &other) const
{
    LinkedList<T1> newone;
    newone = *this;
    newone.insert(other.data, newone.size);
    return newone;
}

template <typename T1>
LinkedList<T1> &LinkedList<T1>::operator=(const LinkedList<T1> &other)
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
LinkedList<T1> &LinkedList<T1>::operator=(LinkedList<T1> &&other) noexcept
{
    if (this != &other)
    {
        clearAll(); // Clear existing resources

        head = other.head;
        tail = other.tail;
        size = other.size;

        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
    return *this;
}

template <typename T1>
LinkedList<T1> &LinkedList<T1>::operator+=(const LinkedList<T1> &other)
{
    *this = *this + other;
    return *this;
}

template <typename T1>
LinkedList<T1> &LinkedList<T1>::operator+=(const NODE<T1> &other)
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
#include <cstdio>
int main()
{
    LinkedList<int> list = {7023, 3090, 2329, 7336, 8956, 340, 9821, 6207, 50, 8324, 4848, 4463, 3829, 418, 9069, 9445, 928, 6271, 4938, 5657, 7786, 3977, 8712, 8736, 1796, 4881, 8926};
    for (auto i : list)
        cout << i << ' ';
    cout << endl;
    list.sort();
    list.reverse();
    for (auto i : list)
        cout << i << ' ';
    cout << endl;
    for (auto i = list.r_begin(); i != list.r_end(); ++i)
        cout << *i << ' ';
    return 0;
}