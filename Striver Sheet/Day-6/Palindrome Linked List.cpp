/*
Palindrome Linked List
======================

Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
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
  ListNode *reverse(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    ListNode *dummy = NULL;
    ListNode *temp = head;
    while (temp)
    {
      auto next = temp->next;
      temp->next = dummy;
      dummy = temp;
      temp = next;
    }
    return dummy;
  }

  bool isPalindrome(ListNode *head)
  {
    if (!head || !head->next)
      return true;
    auto fast = head, slow = head;
    while (fast->next && fast->next->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow->next = reverse(slow->next);

    ListNode *mid = slow, *start = head;
    mid = mid->next;

    while (mid)
    {
      if (start->val != mid->val)
        return false;
      start = start->next;
      mid = mid->next;
    }
    return true;
  }
};
