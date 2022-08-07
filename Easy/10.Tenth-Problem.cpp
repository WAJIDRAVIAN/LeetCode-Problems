/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".


Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p == s)
        {
            return true;
        }

        int sSize = s.length() + 1;
        int pSize = p.length() + 1;
        vector<vector<bool>> result(sSize, vector<bool>(pSize, false));
        result[0][0] = true;
        // initialize result vector, put true each * and . index occurrences of pattern into result vector
        for (int i = 1; i < pSize; i++)
        {
            if (p[i - 1] == '*' && i > 1)
            {
                result[0][i] = result[0][i - 2];
            }
        }
        for (int i = 1; i < sSize; i++)
        {
            for (int j = 1; j < pSize; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    result[i][j] = result[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    result[i][j] = result[i][j - 2];
                    if (j > 1)
                    {
                        if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                        {
                            result[i][j] = result[i][j] || result[i - 1][j];
                        }
                    }
                }
                else
                {
                    result[i][j] = false;
                }
            }
        }
        return result[sSize-1][pSize-1];
    }
};

int main()
{
    Solution s;
    cout << s.isMatch("mississippi", "mis*is*ip*.") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ab", ".*") << endl;
    return 0;
}
