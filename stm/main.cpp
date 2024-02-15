#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
struct product
{
    string p;
    int a, b, c;
};

istream &operator>>(istream &os, product &input)
{
    os >> input.p >> input.a >> input.b >> input.c;
    return os;
}

ostream &operator<<(ostream &os, product &output)
{
    os << output.p << " " << output.a << " " << output.b << " " << output.c << endl;
    return os;
}
int main()
{
    string tmp;
    vector<product> p;
    ifstream file("products.txt");
    while (getline(file, tmp))
    {
        istringstream sin(tmp);
        product pro;
        sin >> pro;
        if (!sin)
        {
            cout << "Error in reading the line: " << tmp << endl;
            continue;
        }
        // cout << pro;
        p.push_back(move(pro));
    }
    for (product i : p)
        cout << i;
    return 0;
}