
vector<int> rightView(Node *root)
{
  if (!root)
    return {};
  queue<Node *> pending;
  pending.push(root);
  vector<int> ans;

  while (pending.size())
  {
    int s = pending.size();
    for (int i = 0; i < s; ++i)
    {
      auto n = pending.front();
      pending.pop();
      if (i == s - 1)
        ans.push_back(n->data);
      if (n->left)
        pending.push(n->left);
      if (n->right)
        pending.push(n->right);
    }
  }

  return ans;
}
