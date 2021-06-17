/*
Reverse a Linked List in groups of given size
==============================================

Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:
Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.

Example 2:
Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 104
1 <= k <= N
*/

struct node *reverse(struct node *head, struct node *tail)
{
  if (head == tail)
    return head;
  node *rest = reverse(head->next, tail);
  head->next->next = head;
  head->next = NULL;
  return rest;
}

struct node *reverse(struct node *head, int k)
{
  if (!head || !head->next)
    return head;

  node *tail = head;
  for (int i = 1; i < k && tail->next; ++i)
  {
    tail = tail->next;
  }

  node *prev = reverse(tail->next, k);
  node *nh = reverse(head, tail);
  head->next = prev;

  return nh;
}