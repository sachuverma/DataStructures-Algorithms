/*
Design a stack with operations on middle element
================================================

How to implement a stack which will support following operations in O(1) time complexity? 

1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 
*/

#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List Node */
class DLLNode
{
public:
  DLLNode *prev;
  int data;
  DLLNode *next;
};

/* Representation of the stack data structure
that supports findMiddle() in O(1) time.
The Stack is implemented using Doubly Linked List.
It maintains pointer to head node, pointer to
middle node and count of nodes */
class myStack
{
public:
  DLLNode *head;
  DLLNode *mid;
  int count;
};

/* Function to create the stack data structure */
myStack *createMyStack()
{
  myStack *ms = new myStack();
  ms->count = 0;
  return ms;
};

/* Function to push an element to the stack */
void push(myStack *ms, int new_data)
{
  /* allocate DLLNode and put in data */
  DLLNode *new_DLLNode = new DLLNode();
  new_DLLNode->data = new_data;

  /* Since we are adding at the beginning,
	prev is always NULL */
  new_DLLNode->prev = NULL;

  /* link the old list off the new DLLNode */
  new_DLLNode->next = ms->head;

  /* Increment count of items in stack */
  ms->count += 1;

  /* Change mid pointer in two cases
	1) Linked List is empty
	2) Number of nodes in linked list is odd */
  if (ms->count == 1)
  {
    ms->mid = new_DLLNode;
  }
  else
  {
    ms->head->prev = new_DLLNode;

    if (!(ms->count & 1)) // Update mid if ms->count is even
      ms->mid = ms->mid->prev;
  }

  /* move head to point to the new DLLNode */
  ms->head = new_DLLNode;
}

/* Function to pop an element from stack */
int pop(myStack *ms)
{
  /* Stack underflow */
  if (ms->count == 0)
  {
    cout << "Stack is empty\n";
    return -1;
  }

  DLLNode *head = ms->head;
  int item = head->data;
  ms->head = head->next;

  // If linked list doesn't
  // become empty, update prev
  // of new head as NULL
  if (ms->head != NULL)
    ms->head->prev = NULL;

  ms->count -= 1;

  // update the mid pointer when
  // we have odd number of
  // elements in the stack, i,e
  // move down the mid pointer.
  if ((ms->count) & 1)
    ms->mid = ms->mid->next;

  free(head);

  return item;
}

// Function for finding middle of the stack
int findMiddle(myStack *ms)
{
  if (ms->count == 0)
  {
    cout << "Stack is empty now\n";
    return -1;
  }

  return ms->mid->data;
}
// Function for deleting middle of the stack
int deletemiddle(myStack *ms)
{
  int temp = ms->mid->data;
  ms->mid->prev->next = ms->mid->next;
  ms->mid->next->prev = ms->mid->prev->next;

  delete ms->mid;
  return temp;
}

int main()
{
  /* Let us create a stack using push() operation*/
  myStack *ms = createMyStack();
  push(ms, 11);
  push(ms, 22);
  push(ms, 33);
  push(ms, 44);
  push(ms, 55);
  push(ms, 66);
  push(ms, 77);

  cout << "Item popped is " << pop(ms) << endl;
  cout << "Item popped is " << pop(ms) << endl;
  cout << "Middle Element is " << findMiddle(ms) << endl;
  cout << "deleted mid element " << deletemiddle(ms) << endl;
  return 0;
}
