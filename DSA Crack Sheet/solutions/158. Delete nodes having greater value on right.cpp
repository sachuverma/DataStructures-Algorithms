
Node *compute(Node *head)
{
  if (!head || !(head->next))
    return head;
  Node *temp = head;
  Node *prev = NULL;
  Node *nextnode;
  while (temp && temp->next)
  {
    Node *temp2 = temp->next;
    while (temp2)
    {
      if (temp2->data > temp->data)
        break;
      temp2 = temp2->next;
    }

    if (temp2)
    {
      nextnode = temp->next;
      if (prev == NULL)
      {
        head = nextnode;
      }
      else
      {
        prev->next = nextnode;
      }
      free(temp);
      temp = nextnode;
    }
    else
    {
      prev = temp;
      temp = temp->next;
    }
  }
  return head;
}
