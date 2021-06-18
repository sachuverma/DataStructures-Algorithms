/*
Merge Sort for Linked List
==========================

Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:
Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.

Example 2:
Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= N <= 105
*/

Node *midNode(Node *head)
{
  auto fast = head, slow = head;
  while (fast && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

Node *merge(Node *head1, Node *head2)
{
  Node *ans = new Node(-1);
  auto temp = ans, temp1 = head1, temp2 = head2;

  while (temp1 && temp2)
  {
    if (temp1->data < temp2->data)
    {
      auto next = temp1->next;
      temp->next = temp1;
      temp1->next = NULL;
      temp = temp->next;
      temp1 = next;
    }
    else
    {
      auto next = temp2->next;
      temp->next = temp2;
      temp2->next = NULL;
      temp = temp->next;
      temp2 = next;
    }
  }

  if (temp1)
    temp->next = temp1;
  if (temp2)
    temp->next = temp2;

  return ans->next;
}

Node *mergeSort(Node *head)
{
  if (!head || !head->next)
    return head;

  auto mid = midNode(head);
  auto temp = head;

  while (temp->next != mid)
    temp = temp->next;
  temp->next = NULL;

  auto head2 = mid;

  head = mergeSort(head);
  head2 = mergeSort(head2);

  return merge(head, head2);
}