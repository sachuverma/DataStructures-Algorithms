
int height(Node *root)
{
  if (!root)
    return 0;
  return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(Node *root)
{
  if (!root)
    return true;
  if (abs(height(root->left) - height(root->right)) > 1)
    return false;
  return isBalanced(root->left) && isBalanced(root->right);
}
