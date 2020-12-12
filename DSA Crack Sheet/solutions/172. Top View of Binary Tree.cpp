
void topView(struct Node *root)
{
  map<int, int> m;
  queue<pair<Node *, int>> q;
  q.push({root, 0});
  int hd = 0;
  while (q.size())
  {
    auto a = q.front();
    q.pop();
    hd = a.second;
    if (m.count(hd) == 0)
      m[hd] = a.first->data;
    if (a.first->left)
      q.push({a.first->left, hd - 1});
    if (a.first->right)
      q.push({a.first->right, hd + 1});
  }

  for (auto it = m.begin(); it != m.end(); ++it)
    cout << it->second << " ";
}
