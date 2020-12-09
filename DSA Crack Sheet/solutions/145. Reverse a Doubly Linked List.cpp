
Node *reverseDLL(Node *head)
{
  //Your code here
  auto temp = head;
  if (!temp || !temp->next)
    return temp;

  while (temp)
  {
    auto tmp = temp->prev;
    temp->prev = temp->next;
    temp->next = tmp;
    temp = temp->prev;
  }

  temp = head;
  while (temp->prev)
    temp = temp->prev;
  return temp;
}
