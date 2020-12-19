
Node *helper(Node *root)
{
  if (!root)
    return root;

  if (root->left)
  {
    auto left = helper(root->left);
    while (left->right)
      left = left->right;
    left->right = root;
    root->left = left;
  }

  if (root->right)
  {
    auto right = helper(root->right);
    while (right->left)
      right = right->left;
    right->left = root;
    root->right = right;
  }

  return root;
}

Node *bToDLL(Node *root)
{
  if (!root)
    return root;
  root = helper(root);

  while (root->left)
  {
    root = root->left;
  }

  return root;
}
