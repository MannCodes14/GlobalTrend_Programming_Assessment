#include <iostream>

int findGCD(int a, int b)
{
    int temp, A, B;

    if (a > b)
    {
        A = a;
        B = b;
    }
    else
    {
        A = b;
        B = a;
    }

    while (B != 0)
    {
        temp = B;
        B = A % B;
        A = temp;
    }

    return A;
}

int main()
{

    int a;

    std::cout << "Enter first number:";
    std::cin >> a;

    int b;

    std::cout << "Enter second number:";
    std::cin >> b;

    int gcd = findGCD(a, b);

    std::cout << "The GCD is :" << findGCD(a, b) << std::endl;
}