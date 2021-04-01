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
  bool isPalindrome(ListNode *head)
  {
    auto slow = head, fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    auto head2 = reverse(slow);
    auto head1 = head;
    while (head2 && head1)
    {
      if (head1->val != head2->val)
        return false;
      head1 = head1->next;
      head2 = head2->next;
    }
    return true;
  }

  ListNode *reverse(ListNode *mid)
  {
    if (!mid || !mid->next)
      return mid;
    auto curr = mid, next = curr->next;
    curr->next = NULL;
    while (next)
    {
      auto nextNext = next->next;
      next->next = curr;
      curr = next;
      next = nextNext;
    }

    return curr;
  }
};
