
bool isPalindrome(Node *head)
{
  stack<int> s;
  auto temp = head;
  while (temp)
  {
    s.push(temp->data);
    temp = temp->next;
  }

  temp = head;
  while (temp && s.size())
  {
    if (temp->data != s.top())
      return false;
    s.pop();
    temp = temp->next;
  }

  return true;
}
