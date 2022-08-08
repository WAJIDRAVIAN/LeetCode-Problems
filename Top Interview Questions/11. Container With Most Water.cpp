/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.



Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1


Constraints:

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int size = height.size();
        if (size == 2)
        {
            if (height[0] > height[1])
                return height[1];
            else
                return height[0];
        }

        int max1 = 0;

        int area = -1;
        int startIndex = 0;
        int endIndex = size - 1;
        for (int i = 0; i < size; i++)
        {
            // calculate last row
            if (height[startIndex] < height[endIndex])
            {
                max1 = height[startIndex] * (endIndex - startIndex);
                startIndex++;
            }
            else if (startIndex != endIndex)
            {
                max1 = height[endIndex] * (endIndex - startIndex);
                endIndex--;
            }

            if (max1 > area)
            {
                area = max1;
            }
        }

        return area;
    }
};
// Driver function definition
int main()
{
    vector<int> height = {2, 1};
    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}
