
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
  Node *cloneGraph(Node *node)
  {
    if (!node)
      return node;

    Node *copy = new Node(node->val);
    queue<Node *> pending;
    pending.push(node);
    unordered_map<Node *, Node *> all_copies;
    all_copies[node] = copy;

    while (pending.size())
    {
      auto curr = pending.front();
      pending.pop();
      for (auto &neighbor : curr->neighbors)
      {
        if (all_copies.find(neighbor) == all_copies.end())
        {
          all_copies[neighbor] = new Node(neighbor->val);
          pending.push(neighbor);
        }
        all_copies[curr]->neighbors.push_back(all_copies[neighbor]);
      }
    }

    return copy;
  }
};
