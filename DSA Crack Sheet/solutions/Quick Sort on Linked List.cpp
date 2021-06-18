/*
Quick Sort on Linked List
=========================

Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

Input:
In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
There are multiple test cases. For each test case, this method will be called individually.

Output:
Set *headRef to head of resultant linked list.

User Task:
The task is to complete the function quickSort() which should set the *headRef to head of the resultant linked list.

Constraints:
1<=T<=100
1<=N<=200

Note: If you use "Test" or "Expected Output Button" use below example format

Example:
Input:
2
3
1 6 2
4
1 9 3 8
Output:
1 2 6
1 3 8 9

Explanation:
Testcase 1: After sorting the nodes, we have 1, 2 and 6.
Testcase 2: After sorting the nodes, we have 1, 3, 8 and 9.
*/

node *getTail(node *curr)
{
  while (curr && curr->next)
    curr = curr->next;
  return curr;
}

node *partition(node *head, node *end, node **newHead, node **newEnd)
{
  node *pivot = end;
  node *prev = NULL, *cur = head, *tail = pivot;

  while (cur != pivot)
  {
    if (cur->data < pivot->data)
    {
      if ((*newHead) == NULL)
        (*newHead) = cur;

      prev = cur;
      cur = cur->next;
    }
    else
    {
      if (prev)
        prev->next = cur->next;
      node *tmp = cur->next;

      cur->next = NULL;
      tail->next = cur;
      tail = cur;
      cur = tmp;
    }
  }

  if ((*newHead) == NULL)
    (*newHead) = pivot;
  (*newEnd) = tail;
  return pivot;
}

node *helper(node *head, node *tail)
{
  if (!head || head == tail)
    return head;

  node *newHead = NULL, *newTail = NULL;
  auto pivot = partition(head, tail, &newHead, &newTail);
  if (newHead != pivot)
  {
    auto tmp = newHead;
    while (tmp->next != pivot)
      tmp = tmp->next;
    tmp->next = NULL;

    newHead = helper(newHead, tmp);

    tmp = getTail(newHead);
    tmp->next = pivot;
  }

  pivot->next = helper(pivot->next, newTail);
  return newHead;
}

void quickSort(struct node **headRef)
{
  *headRef = helper(*headRef, getTail(*headRef));
}
