/*
Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        const int size = s.size();

        int count = 0;
        int lengthOfLongestSubstring = 0;

        for (int i = 0; i < size; i++)
        {
            bool found[128] = {false};
            for (int j = i; j < size; j++)
            {
                if (found[s[j]])
                {
                    found[s[j]] = false;
                    break;
                }
                else
                {
                    found[s[j]] = true;
                    //cout << s[i] << "=" << s[j] << endl;
                    count++;
                }
            }
           // cout << count << endl;
            if (count > lengthOfLongestSubstring)
            {
                lengthOfLongestSubstring = count;
            }
            count = 0;
        }

        return lengthOfLongestSubstring;
    }
};

int main()
{
    Solution s;
    string str1 = "abcabcbbbb W278 ahmed alias alias";
    cout << s.lengthOfLongestSubstring(str1) << endl;
    return 0;
}
