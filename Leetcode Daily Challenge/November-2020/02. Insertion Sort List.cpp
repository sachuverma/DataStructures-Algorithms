/*
Insertion Sort List
===================

Sort a linked list using insertion sort.

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
  ListNode *insertionSortList(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    auto sorted = head, unsorted = head->next;

    while (unsorted)
    {
      auto dummy = sorted;
      while (dummy->val < unsorted->val)
        dummy = dummy->next;
      if (!dummy || !dummy->next)
        break;

      auto swapNode = dummy;
      int prev = swapNode->val, curr = swapNode->next->val;

      while (swapNode != unsorted)
      {
        curr = swapNode->next->val;
        swapNode->next->val = prev;
        prev = curr;
        swapNode = swapNode->next;
      }
      dummy->val = prev;
      unsorted = unsorted->next;
    }

    return head;
  }
};
