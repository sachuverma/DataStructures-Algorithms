
int height(struct Node *node)
{
  if (!node)
    return 0;
  int left = height(node->left);
  int right = height(node->right);

  return max(left, right) + 1;
}
