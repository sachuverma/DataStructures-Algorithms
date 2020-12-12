
vector<int> zigZagTraversal(Node *root)
{
  vector<int> ans;
  if (!root)
    return ans;
  queue<Node *> pending;
  pending.push(root);
  bool zigzag = false;

  while (pending.size())
  {
    int size = pending.size();
    vector<int> subans;
    for (int i = 0; i < size; ++i)
    {
      auto node = pending.front();
      pending.pop();
      subans.push_back(node->data);
      if (node->left)
        pending.push(node->left);
      if (node->right)
        pending.push(node->right);
    }

    if (zigzag)
      reverse(subans.begin(), subans.end());
    zigzag = !zigzag;
    for (auto &i : subans)
      ans.push_back(i);
  }
  return ans;
}
