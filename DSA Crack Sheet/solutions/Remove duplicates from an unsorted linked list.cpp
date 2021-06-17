/*
Remove duplicates from an unsorted linked list
=================================================

Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:
Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4

Example 2:
Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are
2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements
2 from the linked list and the resultant
linked list will contain only 2.
Your Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= size of linked lists <= 106
0 <= numbers in list <= 104
*/

Node *removeDuplicates(Node *head)
{
  if (!head || !head->next)
    return head;
  vector<int> vis(10001, 0);
  vis[head->data]++;

  auto curr = head;
  while (curr && curr->next)
  {
    auto next = curr->next;
    if (vis[next->data] == 0)
    {
      curr = curr->next;
      vis[next->data] = 1;
    }
    else
      curr->next = curr->next->next;
  }

  return head;
}