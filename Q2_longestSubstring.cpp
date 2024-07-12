// Given a string, find the length of the longest substring without repeating characters.The function should return an integer representing the length of the longest substring without repeating characters.

#include <iostream>
#include <string>

int substringLen(std::string s)
{
    int l = 0;
    int r = 0;
    int ans = 0;
    int count[256] = {0};

    while (r < s.length())
    {

        count[s[r]]++;

        while (count[s[r]] > 1)
        {
            count[s[l]]--;
            l++;
        }

        ans = std::max(ans, r - l + 1);
        r++;
    }
    
    return ans;
}

int main()
{
    std::string s = "abcefcabb";
    std::cout << substringLen(s);

    return 0;
}