
bool detectLoop(Node *head)
{
  auto slow = head, fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
      return true;
  }
  return false;
}
