
struct node *getTail(struct node *cur)
{
  while (cur != NULL && cur->next != NULL)
    cur = cur->next;
  return cur;
}

struct node *partition(struct node *head, struct node *end, struct node **newHead, struct node **newEnd)
{
  struct node *pivot = end;
  struct node *prev = NULL, *cur = head, *tail = pivot;

  while (cur != pivot)
  {
    if (cur->data < pivot->data)
    {
      if ((*newHead) == NULL)
        (*newHead) = cur;
      prev = cur;
      cur = cur->next;
    }
    else
    {
      if (prev)
        prev->next = cur->next;
      struct node *tmp = cur->next;
      cur->next = NULL;
      tail->next = cur;
      tail = cur;
      cur = tmp;
    }
  }

  if ((*newHead) == NULL)
    (*newHead) = pivot;
  (*newEnd) = tail;
  return pivot;
}

struct node *quickSortRecur(struct node *head, struct node *end)
{
  if (!head || head == end)
    return head;
  node *newHead = NULL, *newEnd = NULL;
  struct node *pivot = partition(head, end, &newHead, &newEnd);
  if (newHead != pivot)
  {
    struct node *tmp = newHead;
    while (tmp->next != pivot)
      tmp = tmp->next;
    tmp->next = NULL;
    newHead = quickSortRecur(newHead, tmp);
    tmp = getTail(newHead);
    tmp->next = pivot;
  }

  pivot->next = quickSortRecur(pivot->next, newEnd);
  return newHead;
}

void quickSort(struct node **headRef)
{
  (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
  return;
}
