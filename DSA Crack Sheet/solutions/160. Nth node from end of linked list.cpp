
int getNthFromLast(Node *head, int n)
{
  int count = 0;
  Node *temp = head;

  while (temp != NULL)
  {
    temp = temp->next;
    count++;
  }

  if ((count - n) < 0)
  {
    return -1;
  }

  int i = 0;
  temp = head;
  while (i < (count - n))
  {
    temp = temp->next;
    i++;
  }
  return temp->data;
}
