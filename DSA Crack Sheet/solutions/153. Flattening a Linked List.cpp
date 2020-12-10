
Node *merge(Node *a, Node *b)
{
  if (a == NULL)
    return b;
  if (b == NULL)
    return a;
  Node *result;
  if (a->data < b->data)
  {
    result = a;
    result->bottom = merge(a->bottom, b);
  }
  else
  {
    result = b;
    result->bottom = merge(a, b->bottom);
  }
  result->next = NULL;
  return result;
}

Node *flatten(Node *root)
{
  if (root == NULL || root->next == NULL)
    return root;
  return merge(root, flatten(root->next));
}
