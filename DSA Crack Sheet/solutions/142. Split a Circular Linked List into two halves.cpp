
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
  Node *slow_ptr = head;
  Node *fast_ptr = head;

  if (head == NULL)
    return;
  while (fast_ptr->next != head && fast_ptr->next->next != head)
  {
    fast_ptr = fast_ptr->next->next;
    slow_ptr = slow_ptr->next;
  }

  if (fast_ptr->next->next == head)
    fast_ptr = fast_ptr->next;
  *head1_ref = head;
  if (head->next != head)
    *head2_ref = slow_ptr->next;
  fast_ptr->next = slow_ptr->next;
  slow_ptr->next = head;
}
