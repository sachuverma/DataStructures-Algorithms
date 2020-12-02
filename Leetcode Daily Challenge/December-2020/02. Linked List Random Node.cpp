/*
Linked List Random Node
=======================

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
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
  ListNode *head;
  long long size;

public:
  /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode *head)
  {
    this->head = head;
    this->size = getSize();
  }

  long long getSize()
  {
    long long ans = 0;
    auto temp = head;
    while (temp)
    {
      temp = temp->next;
      ans++;
    }
    return ans;
  }

  /** Returns a random node's value. */
  int getRandom()
  {
    long long randomNum = rand() % size;
    auto temp = head;
    while (randomNum > 0)
    {
      temp = temp->next;
      randomNum--;
    }
    return temp ? temp->val : 0;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
