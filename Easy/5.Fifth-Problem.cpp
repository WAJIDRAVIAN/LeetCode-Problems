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
    // calculate length of given string
    int length = 0;
    int leftPivot = 0;
    int rightPivot = 0;
    int maxLength = 0;
    string temp = "";
    string result = "";

public:
    string longestPalindrome(string s)
    {
        if(s.size() == 1 || s.size() == 0)
            return s;
        length = s.size();
        for (int i = 0; i < length / 2; i++)
        {
            leftPivot = length / 2 - i - 1;
            rightPivot = leftPivot + 1;
            // for even length string
            check_palindrom(s);

            // for even length string
            rightPivot = length / 2 + i + 1;
            leftPivot = rightPivot - 1;
            check_palindrom(s);

            // for odd length string
            leftPivot = length / 2 - i;
            rightPivot = leftPivot;
            check_palindrom(s);

            // for odd length string
            rightPivot = length / 2 + i;
            leftPivot = rightPivot;
            check_palindrom(s);
        }

        return result;
    }

    void check_palindrom(string s)
    {
        for (int j = 0; j < length / 2 + 1 && leftPivot >= 0 && rightPivot < length; j++)
        {
            //cout << "leftPivot: " << leftPivot << " rightPivot: " << rightPivot << endl;

            if (s[leftPivot] == s[rightPivot])
            {
                leftPivot--;
                rightPivot++;
            }
            else
            {
                break;
            }
        }
        // temp = s.substr(leftPivot, rightPivot - leftPivot);
        temp = "";
        for (int i = leftPivot + 1; i < rightPivot; i++)
        {
            temp += s[i];
        }
        if (result.size() < temp.size())
        {
            result = temp;
            
        }
    }
};

int main()
{
    Solution s;
    string str = "a"; //"gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}