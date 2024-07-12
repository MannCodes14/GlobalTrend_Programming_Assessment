// Write a function to find the maximum difference between any two elements in an array.The function should return the maximum difference between any two elements in the array.


#include <iostream>
#include <vector>

using namespace std;

int findMaxDiff(vector<int> arr)
{
    int min_val = arr[0];
    int max_val = arr[0];

    for (int i : arr)
    {
        if (i < min_val)
        {
            min_val = i;
        }

        if (i > max_val)
        {
            max_val = i;
        }
    }

    return max_val - min_val;
}

int main()
{
    vector<int> arr = {1, 3, 2, 5, 7, 9, 2};
    int maxDiff = findMaxDiff(arr);
    std::cout << "Max difference between the elements of array is :" << maxDiff << " ";
}