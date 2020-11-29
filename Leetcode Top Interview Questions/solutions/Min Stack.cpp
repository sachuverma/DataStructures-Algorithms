/*
Min Stack
=========

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:
Methods pop, top and getMin operations will always be called on non-empty stacks.

Hint #1  
Consider each node in the stack having a minimum value. (Credits to @aakarshmadhavan)
*/

class MinStack
{
  stack<int> s1, s2;

public:
  /** initialize your data structure here. */
  MinStack()
  {
  }

  void push(int x)
  {
    if (s1.empty())
    {
      s1.push(x);
      s2.push(x);
    }
    else
    {
      int curr_min = s2.top();
      s1.push(x);
      if (curr_min > x)
        s2.push(x);
      else
        s2.push(curr_min);
    }
  }

  void pop()
  {
    if (s1.size())
    {
      s1.pop();
      s2.pop();
    }
  }

  int top()
  {
    if (s1.size())
      return s1.top();
    return -1;
  }

  int getMin()
  {
    if (s1.size())
      return s2.top();
    return -1;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
