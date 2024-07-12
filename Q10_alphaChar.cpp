#include <iostream>

bool IsAlpha(std::string s)
{
    for (char c : s)
    {
        if (!(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            return false;
        }
    }

    return true;
}

int main()
{

    std::string str;
    std::cin >> str;

    if (IsAlpha(str) == false)
    {
        std::cout << str << " has a non-alphabateic character!";
    }
    else
    {
        std::cout << str << " does not have a non-aplhabetic character!";
    }
}