/*
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // get length of input string
        int n = s.size();
        string result = "";
        // All substrings of length 1
        // are palindromes
        int maxLength = 1, start = 0;

        // Nested loop to mark start and end index
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                int flag = 1;

                // Check palindrome
                for (int k = 0; k < (j - i + 1) / 2; k++)
                    if (s[i + k] != s[j - k])
                    {
                        flag = 0;
                    }

                // Palindrome
                if (flag && (j - i + 1) > maxLength)
                {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }
        for (int i = start; i <= start + maxLength - 1; ++i)
            result = result + s[i];
        return result;
    }
};

int main()
{

    Solution s;
    string str = "abaabaab";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}