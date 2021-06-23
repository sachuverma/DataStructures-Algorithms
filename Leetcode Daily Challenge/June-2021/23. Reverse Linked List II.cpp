/*
Reverse Linked List II
=======================

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

Follow up: Could you do it in one pass?
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
  ListNode *reverse(ListNode *head, ListNode *tail)
  {
    if (head == tail || !head || head->next == tail)
      return head;
    auto curr = head, prev = tail;
    while (curr && curr != tail)
    {
      auto next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  ListNode *reverseBetween(ListNode *head, int l, int r)
  {
    auto temp = head, left = head, right = head;

    for (int i = 1; i <= max(l, r); ++i)
    {
      if (i < l - 1)
        temp = temp->next;
      if (i < l)
        left = left->next;
      if (i <= r)
        right = right->next;
    }

    if (l == 1)
      return reverse(left, right);

    temp->next = reverse(left, right);
    ;
    return head;
  }
};