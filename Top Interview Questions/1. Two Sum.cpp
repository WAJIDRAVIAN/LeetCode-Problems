/*
LeetCode
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length=nums.size();
        vector<int> indices;
        for (int i=0; i<length; i++) {
            for (int j=i+1; j<length; j++)
            {
                if (target == nums[j]+nums[i])
                {
                    return indices={i,j};
                }   
            }          
        }
        return indices;
    }
};


// Driver Function
int main()
{
    vector<int> nums={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28};
    int target=3;
    Solution s;
    vector<int> indices = s.twoSum(nums,target);
    cout << "1st index:"<<indices[0]<<"\n2nd index:"<<indices[1]<<endl;

    return 0;
}