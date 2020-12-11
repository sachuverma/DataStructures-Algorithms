

int height(Node *root, int &ans)
{
  if (root == NULL)
    return 0;
  int left_height = height(root->left, ans);
  int right_height = height(root->right, ans);
  ans = max(ans, 1 + left_height + right_height);
  return 1 + max(left_height, right_height);
}

int diameter(Node *root)
{
  if (root == NULL)
    return 0;
  int ans = INT_MIN;
  int height_of_tree = height(root, ans);
  return ans;
}
