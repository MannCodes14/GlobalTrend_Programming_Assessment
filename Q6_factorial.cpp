// Write a function to find the factorial of a given number.The function should return the factorial of the number.

#include <iostream>

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << "factorial of " << n << " is " << fact(n);
}