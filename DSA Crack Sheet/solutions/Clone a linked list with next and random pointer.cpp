/*
Clone a linked list with next and random pointer
===================================================

You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers , where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

ArbitLinked List1

Example 1:
Input:
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there
re 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbit pointer
set, rest two nodes have arbit pointer
as NULL. Second line tells us the value
of four nodes. The third line gives the
information about arbitrary pointers.
The first node arbit pointer is set to
node 2.  The second node arbit pointer
is set to node 4.

Example 2:
Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase ,
applying the method as stated in the
above example, the output will be 1.
Your Task:
The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned and should return the head of the cloned linked list.
NOTE : If their is any node whose arbitrary pointer is not given then its by default null.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100
*/

Node *copyList(Node *head)
{
  auto temp = head;
  while (temp)
  {
    Node *newNode = new Node(temp->data);
    auto next = temp->next;
    temp->next = newNode;
    newNode->next = next;
    temp = next;
  }

  temp = head;
  while (temp)
  {
    if (temp->arb)
      temp->next->arb = temp->arb->next;
    temp = temp->next->next;
  }

  temp = head;
  Node *newHead = new Node(-1);
  auto temp2 = newHead;

  while (temp)
  {
    auto next = temp->next->next;
    temp2->next = temp->next;
    temp2 = temp2->next;

    temp->next = next;
    temp = temp->next;
  }

  return newHead->next;
}
