/*
Check if Linked List is Palindrome
====================================

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.

Example 2:
Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105
*/

Node *findMid(Node *head)
{
  Node *fast = head, *slow = head;
  while (fast && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

Node *reverse(Node *head)
{
  Node *curr = head, *prev = NULL;
  while (curr)
  {
    auto next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

bool isPalindrome(Node *head)
{
  if (!head || !head->next)
    return true;

  auto mid = findMid(head);
  auto temp = head;

  while (temp->next != mid)
    temp = temp->next;
  temp->next = NULL;

  auto head1 = head;
  auto head2 = reverse(mid);

  while (head1 && head2)
  {
    if (head1->data != head2->data)
      return false;
    head1 = head1->next;
    head2 = head2->next;
  }
  return true;
}