/*
Add two numbers represented by linked lists
==============================================

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).

Example 2:
Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M))

Constraints:
1 <= N, M <= 5000
*/

Node *reverse(Node *head)
{
  if (!head || !head->next)
    return head;
  auto prev = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return prev;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
  first = reverse(first);
  second = reverse(second);

  Node *newHead = new Node(-1);
  auto temp = newHead;

  int carry = 0;

  while (first || second)
  {
    carry += (first != NULL) ? first->data : 0;
    carry += (second != NULL) ? second->data : 0;
    Node *newNode = new Node(carry % 10);
    temp->next = newNode;
    temp = temp->next;
    carry = carry / 10;

    if (first)
      first = first->next;
    if (second)
      second = second->next;
  }

  while (carry)
  {
    Node *newNode = new Node(carry % 10);
    temp->next = newNode;
    temp = temp->next;
    carry = carry / 10;
  }

  return reverse(newHead->next);
}