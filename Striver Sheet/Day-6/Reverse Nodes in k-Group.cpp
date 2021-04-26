/*
Reverse Nodes in k-Group
========================

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:
Could you solve the problem in O(1) extra memory space?

You may not alter the values in the list's nodes, only nodes itself may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Example 3:
Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]

Example 4:
Input: head = [1], k = 1
Output: [1]

Constraints:
The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    auto curr = head;
    int count = 0;
    while (curr && count != k)
    {
      count++;
      curr = curr->next;
    }

    if (count == k)
    {
      auto prev_ans = reverseKGroup(curr, k);
      while (count-- > 0)
      {
        auto temp = head->next;
        head->next = prev_ans;
        prev_ans = head;
        head = temp;
      }
      head = prev_ans;
    }
    return head;
  }
};
