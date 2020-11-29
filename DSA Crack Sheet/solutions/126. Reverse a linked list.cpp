
struct Node *reverseList(struct Node *head)
{
  if (!head || !head->next)
    return head;
  auto prev = head, curr = head->next, next = head->next->next;
  while (curr)
  {
    curr->next = prev;
    prev = curr;
    curr = next;
    if (!next)
      break;
    else
      next = next->next;
  }
  head->next = NULL;
  head = prev;
  return head;
}
