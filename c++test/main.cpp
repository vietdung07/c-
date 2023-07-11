// #include <iostream>
// #include "mainc.c"

// void *operator new(size_t size)
// {
// 	std::cout << "Custom operator new called. Size: " << size << " bytes\n";
// 	void *ptr = std::malloc(size);
// 	return ptr;
// }

// void operator delete(void *ptr) noexcept
// {
// 	std::cout << "Custom operator delete called.\n";
// 	std::free(ptr);
// }

// class MyClass
// {
// 	// Class implementation
// };

// int main()
// {
// 	MyClass *obj = new MyClass; // Calls the overloaded operator new
// 	delete obj;					// Calls the overloaded operator delete
// 	return 0;
//}
#include <iostream>
#include <random>
#include <string>
#include <windows.h>
using namespace std;
int main()
{
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(0, 15);
	string init = "0123456789ABCDEF";
	// while (true)
	// {
	// for (int i = 0; i < 16; i++)
	// for (int j = 0; j < 16; j++)
	// {
	const char *k = "hello world";
	string s = k;
	char *haha = &s[0];
	// Sleep(200);
	// }
	// }
}