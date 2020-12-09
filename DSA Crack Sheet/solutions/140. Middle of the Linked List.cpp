
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
  ListNode *middleNode(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    auto fast = head, slow = head;
    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};
