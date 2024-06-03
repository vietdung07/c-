// CPP program to illustrate *char
#include <iostream>
#include <string>
#include <cstdio>
// #include <cstdint>
using namespace std;
#define INT_MAXX static_cast<int>((1u + ~1u) / 2)
#define INT_MINN -INT_MAXX - 1
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
	float a;
	scanf("%d", &a);
	printf("%d\n", a);
	return 07777;
}
