

struct compare
{
  bool operator()(
      struct Node *a, struct Node *b)
  {
    return a->data > b->data;
  }
};

Node *mergeKLists(Node *arr[], int N)
{
  priority_queue<Node *, vector<Node *>, compare> pq;
  for (int i = 0; i < N; ++i)
    pq.push(arr[i]);

  Node *dummy = new Node(-1);
  auto temp = dummy;
  while (pq.size())
  {
    auto node = pq.top();
    pq.pop();
    Node *t = new Node(node->data);
    temp->next = t;
    temp = temp->next;
    if (node->next)
      pq.push(node->next);
  }

  return dummy->next;
}
