
vector<int> reverseLevelOrder(Node *root)
{
  if (!root)
    return {};
  queue<Node *> pending;
  pending.push(root);
  vector<int> ans;
  while (pending.size())
  {
    int size = pending.size();
    vector<int> subans;
    for (int i = 0; i < size; ++i)
    {
      auto n = pending.front();
      pending.pop();
      subans.push_back(n->data);
      if (n->left)
        pending.push(n->left);
      if (n->right)
        pending.push(n->right);
    }
    for (int i = subans.size() - 1; i >= 0; --i)
      ans.push_back(subans[i]);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
