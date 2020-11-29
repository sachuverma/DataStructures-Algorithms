
Node *removeDuplicates(Node *root)
{
  if (!root || !root->next)
    return root;
  auto temp = root;
  while (temp->next)
  {
    if (temp->data == temp->next->data)
      temp->next = temp->next->next;
    else
      temp = temp->next;
  }
  return root;
}
