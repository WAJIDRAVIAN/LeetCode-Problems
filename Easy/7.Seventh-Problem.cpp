/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x<10 && x>-10)
            return x;

        string s = to_string(x);
        cout<<s<<endl;
        int length = s.size();
        string result = "";
        for (int i = 0; i < length; i++)
        {
            result.push_back(s[length-i-1]);
        }
        long int temp=stoul(result);
        if(x<0)
            temp=temp;
        if (temp<-2147483648 || temp>2147483647)
            return 0;
        if (x<2147483647 && x>=0)
            return temp;
        else
            return (-temp);
    }
};

int main()
{
    Solution s;
    cout<<s.reverse(123)<<endl;
    return 0;
}