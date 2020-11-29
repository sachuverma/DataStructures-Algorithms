
void removeLoop(Node *head)
{
  auto slow = head, fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
      break;
  }

  if (!fast || !fast->next)
    return;
  slow = head;
  while (slow != fast)
  {
    slow = slow->next;
    fast = fast->next;
  }

  while (fast->next != slow)
    fast = fast->next;
  fast->next = NULL;
}
