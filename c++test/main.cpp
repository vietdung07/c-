// CPP program to illustrate *char
#include <iostream>
#include <string>
#include <cstdint>
using namespace std;
class test
{
private:
public:
	test() : data(0){};
	test(const test &other)
	{
		data = other.data - other.data;
		cout << "\ncall copy constructor";
	}
	int data;
};
test haha()
{
	test k;
	k.data = 100;
	return k;
}
int main(int argc, char **argv)
{
	long long a = 1;
	constexpr int k = 100;
	cout << -static_cast<long long>((1ull + ~1ull) / 2) - 1;
	return 0;
}
