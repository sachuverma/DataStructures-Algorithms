

void printLeaves(struct Node *root, vector<int> &ans)
{
  if (root == NULL)
    return;

  printLeaves(root->left, ans);

  if (!(root->left) && !(root->right))
    ans.push_back(root->data);

  printLeaves(root->right, ans);
}

void printBoundaryLeft(struct Node *root, vector<int> &ans)
{
  if (root == NULL)
    return;

  if (root->left)
  {
    ans.push_back(root->data);
    printBoundaryLeft(root->left, ans);
  }
  else if (root->right)
  {
    ans.push_back(root->data);
    printBoundaryLeft(root->right, ans);
  }
}

void printBoundaryRight(struct Node *root, vector<int> &ans)
{
  if (root == NULL)
    return;

  if (root->right)
  {
    printBoundaryRight(root->right, ans);
    ans.push_back(root->data);
  }
  else if (root->left)
  {
    printBoundaryRight(root->left, ans);
    ans.push_back(root->data);
  }
}

vector<int> printBoundary(Node *root)
{
  if (root == NULL)
    return {};

  vector<int> ans;
  ans.push_back(root->data);

  printBoundaryLeft(root->left, ans);
  printLeaves(root->left, ans);
  printLeaves(root->right, ans);
  printBoundaryRight(root->right, ans);

  return ans;
}