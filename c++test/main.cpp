#include <iostream>

void *operator new(size_t size)
{
	std::cout << "Custom operator new called. Size: " << size << " bytes\n";
	void *ptr = std::malloc(size);
	return ptr;
}

void operator delete(void *ptr) noexcept
{
	std::cout << "Custom operator delete called.\n";
	std::free(ptr);
}

class MyClass
{
	// Class implementation
};

int main()
{
	MyClass *obj = new MyClass; // Calls the overloaded operator new
	delete obj;					// Calls the overloaded operator delete
	return 0;
}
