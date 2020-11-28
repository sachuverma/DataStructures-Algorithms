
Node *midPoint(Node *a)
{
  if (a == NULL || a->next == NULL)
    return a;

  Node *slow = a;
  Node *fast = a->next;
  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

Node *merge(Node *a, Node *b)
{
  if (a == NULL)
    return b;
  else if (b == NULL)
    return a;

  Node *c;
  if (a->data < b->data)
  {
    c = a;
    c->next = merge(a->next, b);
  }
  else
  {
    c = b;
    c->next = merge(a, b->next);
  }
  return c;
}

Node *mergeSort(Node *a)
{
  if (a == NULL || a->next == NULL)
    return a;

  Node *mid = midPoint(a);
  Node *aa = a;
  Node *b = mid->next;
  mid->next = NULL;
  aa = mergeSort(a);
  b = mergeSort(b);

  Node *c = merge(aa, b);
  return c;
}
