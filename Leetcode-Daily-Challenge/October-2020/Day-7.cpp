/*
Rotate List
===========

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

/* Language: C++ 
==================
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
  ListNode *rotateRight(ListNode *head, int k)
  {
    int size = 0;
    auto temp = head, temp2 = head, tail = head;
    while (temp)
    {
      size++;
      temp = temp->next;
      if (tail->next)
        tail = tail->next;
    }

    if (size <= 1)
      return head;

    k = k % size;
    if (k)
    {
      int count = size - k;
      temp = head;
      while (--count)
        temp = temp->next;
      temp2 = temp->next;
      temp->next = NULL;
      tail->next = head;
      head = temp2;
    }

    return head;
  }
};