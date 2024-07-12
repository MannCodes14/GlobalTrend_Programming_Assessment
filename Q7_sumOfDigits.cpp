#include <iostream>

int sumOfDigits(int n)
{
    int temp = n;
    int sum = 0;
    int remainder = 0;

    while (temp > 0)
    {
        remainder = temp % 10;
        sum += remainder;
        temp = temp / 10;
    }

    return sum;
}

int main()
{

    int n;
    std::cin >> n;
    std::cout << sumOfDigits(n);

    return 0;
}