
void mirrorify(node *root)
{
  if (!root)
    return;

  mirrorify(root->left);
  mirrorify(root->right);

  auto temp = root->left;
  root->left = root->right;
  root->right = temp;
}
