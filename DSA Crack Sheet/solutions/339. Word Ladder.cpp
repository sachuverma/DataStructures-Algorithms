
class Solution
{
public:
  int ladderLength(string begin, string end, vector<string> &words)
  {
    unordered_set<string> not_visited(words.begin(), words.end());
    if (not_visited.find(end) == not_visited.end())
      return 0;

    queue<string> pending;
    pending.push(begin);
    int depth = 0;

    while (pending.size())
    {
      int size = pending.size();
      for (int i = 0; i < size; ++i)
      {
        auto curr = pending.front();
        pending.pop();
        if (curr == end)
          return depth + 1;
        for (int j = 0; j < curr.size(); ++j)
        {
          char original = curr[j];
          for (char c = 'a'; c <= 'z'; ++c)
          {
            curr[j] = c;
            if (c == original)
              continue;
            if (not_visited.find(curr) == not_visited.end())
              continue;
            not_visited.erase(curr);
            pending.push(curr);
          }
          curr[j] = original;
        }
      }
      depth++;
    }

    return 0;
  }
};
