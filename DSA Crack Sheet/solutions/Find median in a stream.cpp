/*
Find median in a stream
========================

Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:
Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 

Example 2:
Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5) 
10 goes to stream --> median 7.5 (5,10) 
15 goes to stream --> median 10 (5,10,15) 
Your Task:
You are required to complete the class Solution. 
It should have 2 data members to represent 2 heaps. 
It should have the following member functions:
insertHeap() which takes x as input and inserts it into the heap, the function should then call balanceHeaps() to balance the new heap.
balanceHeaps() does not take any arguments. It is supposed to balance the two heaps.
getMedian() does not take any arguments. It should return the current median of the stream.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)

Constraints:
1 <= N <= 106
1 <= x <= 106
*/

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

//Function to insert heap.
void insertHeap(int &x)
{
  max_pq.push(x);
  balanceHeaps();
}

//Function to balance heaps.
void balanceHeaps()
{
  if (max_pq.size() > min_pq.size() + 1)
  {
    min_pq.push(max_pq.top());
    max_pq.pop();
  }

  if (max_pq.size() && min_pq.size() && max_pq.top() > min_pq.top())
  {
    min_pq.push(max_pq.top());
    max_pq.pop();
  }

  if (min_pq.size() > max_pq.size())
  {
    max_pq.push(min_pq.top());
    min_pq.pop();
  }
}

//Function to return Median.
double getMedian()
{
  if (max_pq.size() > min_pq.size())
    return max_pq.top();
  else
    return (max_pq.top() + min_pq.top()) / 2.0;
}