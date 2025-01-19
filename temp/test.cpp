#include <iostream>
#include <map>
#include <string>

std::string convertToRoman(int number)
{
    const static std::map<int, std::string> reftable = {
        {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"}, {10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"}, {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"}, {100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"}, {1000, "M"}, {2000, "MM"}, {3000, "MMM"}};

    std::string result;
    for (auto it = reftable.rbegin(); it != reftable.rend(); ++it)
    {
        while (number >= it->first)
        {
            result += it->second;
            number -= it->first;
        }
    }
    return result;
}

int main()
{
    int number = 1987; // Example number
    std::cout << "Roman numeral for " << number << " is " << convertToRoman(number) << std::endl;
    return 0;
}