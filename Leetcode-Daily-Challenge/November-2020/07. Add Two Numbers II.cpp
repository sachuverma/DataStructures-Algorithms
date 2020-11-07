/*
Add Two Numbers II
==================

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    if (!head || !head->next)
      return head;
    auto prev = head, curr = head->next, next = head->next->next;
    while (curr)
    {
      curr->next = prev;
      prev = curr;
      curr = next;
      if (!curr)
        break;
      next = curr->next;
    }
    head->next = NULL;
    return prev;
  }

public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    stack<int> n1, n2;
    while (l1)
    {
      n1.push(l1->val);
      l1 = l1->next;
    }

    while (l2)
    {
      n2.push(l2->val);
      l2 = l2->next;
    }

    ListNode *dummy = new ListNode(-1);
    auto temp = dummy;
    int carry = 0;

    while (n1.size() && n2.size())
    {
      int num = n1.top() + n2.top() + carry;
      n1.pop();
      n2.pop();
      carry = num / 10;
      num = num % 10;
      ListNode *newNode = new ListNode(num);
      temp->next = newNode;
      temp = temp->next;
    }

    while (n1.size())
    {
      int num = n1.top() + carry;
      n1.pop();
      carry = num / 10;
      num = num % 10;
      ListNode *newNode = new ListNode(num);
      temp->next = newNode;
      temp = temp->next;
    }

    while (n2.size())
    {
      int num = n2.top() + carry;
      n2.pop();
      carry = num / 10;
      num = num % 10;
      ListNode *newNode = new ListNode(num);
      temp->next = newNode;
      temp = temp->next;
    }

    while (carry)
    {
      int num = carry % 10;
      carry = carry / 10;
      ListNode *newNode = new ListNode(num);
      temp->next = newNode;
      temp = temp->next;
    }

    temp = reverse(dummy->next);
    return temp;
  }
};
