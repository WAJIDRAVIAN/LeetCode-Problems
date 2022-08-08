/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    return 0;
}

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // carry varirable to store carry of two numbers
        int carry = 0;
        // sum varirable to store remainder of sum of two numbers i.e single digit number
        int sum = 0;

        // Create a new list node to store result

        ListNode *result = new ListNode();
        ListNode *temp = result;
        // skip empty lists when    there are no more numbers   in the lists
        while (true)
        {
            if (l1 != nullptr && l2 != nullptr)
            {
                // calculate sum of numbers
                sum = l1->val + l2->val + carry;
                // point to the next nodes
                l1 = l1->next;
                l2 = l2->next;
            }
            //
            else if (l1 != nullptr)
            {
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else if (l2 != nullptr)
            {
                sum = l2->val + carry;
                l2 = l2->next;
            }
            carry = 0;
            if (sum > 9)
            {
                // calculate carry
                carry = sum / 10;
                // calculate single digit sum
                sum = sum % 10;
            }
            temp->val = sum;
            // break out of loop if both lists are nullptr
            if (l1 == nullptr && l2 == nullptr)
            {
                break;
            }
            temp->next = new ListNode();
            temp = temp->next;
        }
        if (carry == 1)
        {
            temp->next = new ListNode();
            temp = temp->next;
            temp->val = carry;
        }
        return result;
    }
};
