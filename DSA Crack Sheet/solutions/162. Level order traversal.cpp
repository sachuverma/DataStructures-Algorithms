
vector<int> levelOrder(Node *node)
{
  if (!node)
    return {};
  vector<int> ans;
  queue<Node *> pending;
  pending.push(node);

  while (pending.size())
  {
    int size = pending.size();
    for (int i = 0; i < size; ++i)
    {
      auto n = pending.front();
      pending.pop();
      ans.push_back(n->data);
      if (n->left)
        pending.push(n->left);
      if (n->right)
        pending.push(n->right);
    }
  }
  return ans;
}
