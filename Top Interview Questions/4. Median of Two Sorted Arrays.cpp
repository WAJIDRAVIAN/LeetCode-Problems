/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = 0;
        int size2 = 0;

        if (nums1.size() == 0)
        {
            size2 = nums2.size();

            if (size2 % 2 == 0)
            {
                size2 = size2 / 2;
                return (nums2[size2 - 1] + nums2[size2]) / float(2);
            }
            else
            {
                size2 = size2 / 2;
                return nums2[size2];
            }
        }
        if (nums2.size() == 0)
        {
            size1 = nums1.size();

            if (size1 % 2 == 0)
            {
                size1 = size1 / 2;
                return (nums1[size1 - 1] + nums1[size1]) / float(2);
            }
            else
            {
                size1 = size1 / 2;
                return nums1[size1];
            }
        }

        size1 = nums1.size();
        size2 = nums2.size();

        int size3 = size1 + size2;
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int mergedArray[2000];

        // Start Merge Arrays code
        while (count1 < size1 && count2 < size2)
        {
            if (nums1[count1] < nums2[count2])
                mergedArray[count3++] = nums1[count1++];
            else
                mergedArray[count3++] = nums2[count2++];
        }
        // Store remaining elements of first array
        while (count1 < size1)
        {
            mergedArray[count3++] = nums1[count1++];
        }

        // Store remaining elements of second array
        while (count2 < size2)
        {
            mergedArray[count3++] = nums2[count2++];
        }

        // Start Findmedian code
        if (size3 % 2 == 0)
        {
            count1 = size3 / 2;
            return (mergedArray[count1 - 1] + mergedArray[count1]) / float(2);
        }
        else
        {
            count1 = size3 / 2;
            return mergedArray[count1];
        }
        // End Findmedian code
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}