/*
Reverse Linked List
===================

Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
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
  ListNode *reverseList(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    if (!head->next->next)
    {
      auto temp = head->next;
      temp->next = head;
      head->next = NULL;
      head = temp;
      return head;
    }
    else
    {
      auto a = head, b = head->next, c = head->next->next;
      while (b)
      {
        b->next = a;
        a = b;
        b = c;
        if (c)
          c = c->next;
        else
          break;
      }
      head->next = NULL;
      head = a;
      return head;
    }
  }
};
