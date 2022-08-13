/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.size() == 1){
            return strs[0];
        }
        int minLength = 200;
        string prefix = "";
        bool match = false;
        int t_strings = strs.size();
        int length = 0;
        // find the smallest length string
        for (int i = 0; i < t_strings; i++)
        {
            length = strs[i].length();
            if (length < minLength)
            {
                minLength = length;
            }
        }
        // find longest common prefix
        for (int i = 0; i < minLength; i++)
        {
            for (int j = 0; j < t_strings - 1; j++)
            {
                if (strs[j][i] == strs[j + 1][i])
                {
                    match = true;
                }
                else
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                prefix = prefix + strs[0][i];
            }
            else
            {
                break;
            }
        }
        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}