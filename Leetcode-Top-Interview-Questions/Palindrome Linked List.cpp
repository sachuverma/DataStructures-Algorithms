/* 
Palindrome Linked List
======================

Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
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
  ListNode *reverse(ListNode *head)
  {
    ListNode *prev = NULL;
    while (head)
    {
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }

public:
  bool isPalindrome(ListNode *head)
  {
    auto slow = head, fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto reversedMid = reverse(slow);
    while (reversedMid)
    {
      if (reversedMid->val != head->val)
        return false;
      reversedMid = reversedMid->next;
      head = head->next;
    }

    return true;
  }
};
