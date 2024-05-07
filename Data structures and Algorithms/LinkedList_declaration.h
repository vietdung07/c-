#ifndef LINKED_LIST_DECLARATION
#define LINKED_LIST_DECLARATION
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

public:
    LinkedList();
    LinkedList(const LinkedList<T1> &other);
    LinkedList(std::initializer_list<T1> args);
    class iterator;
    class iterator
    {
    private:
        NODE<T1> *k;

    public:
        iterator();
        iterator(NODE<T1> *node);
        iterator(const iterator &k);
        T1 &operator*();
        iterator &operator++();
        bool operator!=(const iterator &other);
    };
    iterator begin() const;
    iterator end() const;
    void push_back(T1 data);
    void pop_back();
    void insert(T1 _data, int index = 0);
    void remove(int index = 0);
    void clearAll();
    void sort() const;
    void reverse();
    bool isEmpty();
    const int get_size() const;
    T1 &operator[](int index) const;
    LinkedList<T1> operator+(const LinkedList<T1> other);
    LinkedList<T1> operator+(const NODE<T1> &other);
    LinkedList<T1> &operator=(LinkedList<T1> other);
    LinkedList<T1> &operator+=(LinkedList<T1> other);
    LinkedList<T1> &operator+=(NODE<T1> &other);
    ~LinkedList();
};
#endif