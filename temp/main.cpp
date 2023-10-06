#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
class Student
{
public:
    int id;
    std::string name;
    std::string clas;
    std::string favorite;
    Student(int _id, std::string _name, std::string _class, std::string _favorite) : id(_id), name(_name), clas(_class), favorite(_favorite) {}
    Student() = default;
};
typedef std::map<int, Student> LS;
class List
{
private:
    LS list;

public:
    void add(Student tmp)
    {
        if (list.find(tmp.id) != list.end())
            std::cout << "ID " << tmp.id << " has existed\n";
        else
            list.insert({tmp.id, tmp});
    };
    void remove(int _id)
    {
        if (list.find(_id) != list.end())
            list.erase(_id);
        else
            std::cout << "ID is invalid\n";
    };
    void remove_all() { list.clear(); };
    bool check_existed(int _id) { return list.find(_id) != list.end(); }
    void print_all()
    {
        for (std::pair<const int, Student> &tmp : list)
            std::cout << std::left << std::setw(20) << tmp.second.id << std::setw(20) << tmp.second.name << std::setw(20) << tmp.second.clas << std::setw(20) << tmp.second.favorite << std::endl;
    };
    void print(int _id)
    {
        if (list.find(_id) == list.end())
            std::cout << "ID is invalid\n";
        else
        {
            Student tmp = list.at(_id);
            std::cout << std::left << std::setw(20) << tmp.id << std::setw(20) << tmp.name << std::setw(20) << tmp.clas << std::setw(20) << tmp.favorite << std::endl;
        }
    }
};
int main()
{
    return 0;
}