/*
Remove Nth Node From End of List
================================

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    auto fast = head, slow = head;
    for (int i = 0; i < n; ++i)
      fast = fast->next;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    slow = dummy;
    while (fast)
    {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
  }
};
