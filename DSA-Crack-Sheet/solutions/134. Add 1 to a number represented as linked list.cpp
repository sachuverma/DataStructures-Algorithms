
Node *reverse(Node *head)
{
  if (!head || !head->next)
    return head;
  auto prev = head, curr = head->next, next = head->next->next;
  while (curr)
  {
    curr->next = prev;
    prev = curr;
    curr = next;
    if (!next)
      break;
    else
      next = next->next;
  }
  head->next = NULL;
  head = prev;
  return head;
}

Node *addOne(Node *head)
{
  head = reverse(head);

  int carry = 1;
  auto temp = head;
  while (carry && temp)
  {
    int digit = temp->data + carry;
    carry = digit / 10;
    digit = digit % 10;
    temp->data = digit;
    if (temp->next)
      temp = temp->next;
    else
      break;
  }

  while (carry)
  {
    int digit = carry % 10;
    carry = carry / 10;
    Node *newNode = new Node(digit);
    temp->next = newNode;
    temp = temp->next;
  }

  head = reverse(head);
  return head;
}
