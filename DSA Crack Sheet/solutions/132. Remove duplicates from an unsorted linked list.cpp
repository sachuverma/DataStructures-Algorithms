
Node *removeDuplicates(Node *head)
{
  if (!head || !head->next)
    return head;
  unordered_map<int, int> m;

  auto temp = head;

  temp = head;
  m[temp->data]++;

  while (temp->next)
  {
    if (m.find(temp->next->data) != m.end())
    {
      m[temp->next->data]--;
      temp->next = temp->next->next;
    }

    else
    {
      m[temp->next->data]++;
      temp = temp->next;
    }
  }

  return head;
}
