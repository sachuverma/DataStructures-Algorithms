
Node *copyList(Node *head)
{
  Node *temp = head, *head1 = NULL, *temp2 = NULL;

  while (temp != NULL)
  {
    head1 = new Node(temp->data);
    head1->next = temp->next;
    temp->next = head1;

    temp = temp->next->next;
  }
  temp = head;
  while (temp != NULL)
  {
    if (temp->arb != NULL)
    {
      temp->next->arb = temp->arb->next;
    }
    else
    {
      temp->next->arb = NULL;
    }
    temp = temp->next->next;
  }
  head1 = head->next;
  temp = head;
  while (temp != NULL && temp->next->next != NULL)
  {
    temp2 = temp->next->next;
    temp->next->next = temp->next->next->next;
    temp->next = temp2;

    temp = temp->next;
  }

  temp->next = NULL;
  return head1;
}
