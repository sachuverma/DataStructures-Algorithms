/*
Add 1 to a number represented as linked list
============================================

A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:
Input:
LinkedList: 4->5->6
Output: 457 

Example 2:
Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000
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

Node *addOne(Node *head)
{
  head = reverse(head);

  int carry = 1;
  auto curr = head;

  while (curr && carry)
  {
    int sum = curr->data + carry;
    carry = (sum / 10);
    curr->data = (sum % 10);
    curr = curr->next;
  }

  if (carry)
  {
    curr = head;
    while (curr->next)
      curr = curr->next;

    while (carry)
    {
      Node *newNode = new Node(carry % 10);
      curr->next = newNode;
      curr = curr->next;
      carry = carry / 10;
    }
  }

  head = reverse(head);
  return head;
}