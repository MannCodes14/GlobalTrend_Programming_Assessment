#include <iostream>
#include <vector>

void rotateArray(std::vector<int> &nums, int k)
{

    int n = nums.size();
    k = k % n;

    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k + 1);
    std::reverse(nums.begin() + k + 1, nums.end());
}

int main()
{

    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    std::cout << "Original Array: ";

    for (int num : nums)
    {
        std::cout << num << ", ";
    }

    std::cout << std::endl;
    rotateArray(nums, k);
    std::cout << "after rotating by " << k << std::endl;

    for (int num : nums)
    {
        std::cout << num << ", ";
    }

    std::cout << std::endl;

    return 0;
}