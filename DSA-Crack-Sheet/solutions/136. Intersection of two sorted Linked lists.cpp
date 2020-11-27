
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
  stack<int> n1, n2;
  auto temp = first;
  while (temp)
  {
    n1.push(temp->data);
    temp = temp->next;
  }

  temp = second;
  while (temp)
  {
    n2.push(temp->data);
    temp = temp->next;
  }

  int carry = 0;
  stack<int> ans;

  while (n1.size() || n2.size() || carry)
  {
    int digit1 = n1.size() ? n1.top() : 0;
    int digit2 = n2.size() ? n2.top() : 0;

    if (n1.size())
      n1.pop();
    if (n2.size())
      n2.pop();

    int digit = digit1 + digit2 + carry;
    carry = digit / 10;
    digit = digit % 10;

    ans.push(digit);
  }

  Node *dummy = new Node(-1);
  temp = dummy;
  while (ans.size())
  {
    int digit = ans.top();
    ans.pop();
    Node *newNode = new Node(digit);
    temp->next = newNode;
    temp = temp->next;
  }

  return dummy->next;
}
