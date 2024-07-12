// Write a function to compute the sum of the digits of a given number.The function should return the sum of the digits of the number.


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