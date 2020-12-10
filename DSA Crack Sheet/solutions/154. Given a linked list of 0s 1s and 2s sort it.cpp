
Node *segregate(Node *head)
{
  vector<int> freq(3, 0);
  auto temp = head;
  while (temp)
  {
    freq[temp->data]++;
    temp = temp->next;
  }

  temp = head;
  while (temp)
  {
    if (freq[0] > 0)
    {
      temp->data = 0;
      freq[0]--;
      temp = temp->next;
    }
    else if (freq[1] > 0)
    {
      temp->data = 1;
      freq[1]--;
      temp = temp->next;
    }
    else if (freq[2] > 0)
    {
      temp->data = 2;
      freq[2]--;
      temp = temp->next;
    }
  }
  return head;
}
