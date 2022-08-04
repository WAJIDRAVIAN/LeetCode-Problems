/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;  
        string zigzag="";
        string* arr = new string[numRows];
        int count = 0;
        bool check = false;

        for (int i = 0; i < numRows; i++)
        {
            arr[i] = "";
        }
        for (int i = 0; i < s.size(); i++)
        {
            if(check){
                arr[count].push_back(s[i]);
                if(count == numRows-1){
                    check = false;
                    count = numRows-2;
                }
                else
                {
                    count++;
                }
            }
            else{
                arr[count].push_back(s[i]);
                if(count == 0){
                    check = true;
                    count = 1;
                }
                else
                {
                    count--;
                }
                
            }
        }
        for (int i = 0; i < numRows; i++)
        {
            zigzag += arr[i];
        }
        return zigzag;
    }
};

// Driver program
int main()
{
Solution s;
string s1 = "PAYPALISHIRING";
int numRows = 4;
cout << s.convert(s1, numRows) << endl;
    return 0;
}