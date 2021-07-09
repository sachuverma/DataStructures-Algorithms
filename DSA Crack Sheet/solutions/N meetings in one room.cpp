/*
N meetings in one room
======================

There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Example 1:
Input:
N = 6
S[] = {1,3,0,5,8,5}
F[] = {2,4,6,7,9,9}
Output: 
4
Explanation:
Four meetings can be held with
given start and end timings.

Example 2:
Input:
N = 8
S[] = {75250, 50074, 43659, 8931, 11273,
27545, 50879, 77924}
F[] = {112960, 114515, 81825, 93424, 54316,
35533, 73383, 160252}
Output: 
3
Explanation:
Only three meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that recieves array S[ ] and F[ ] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.

Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 105
0 ≤ S[i] < F[i] ≤ 105
*/

bool static comp(vector<int> &A, vector<int> &B)
{
  if (A[1] == B[1])
    return A[0] < B[0];
  return A[1] < B[1];
}

int maxMeetings(int start[], int end[], int n)
{
  vector<vector<int>> A;
  for (int i = 0; i < n; ++i)
    A.push_back({start[i], end[i]});
  sort(A.begin(), A.end(), comp);

  auto prev = A[0];
  int count = 1;

  for (int i = 1; i < n; ++i)
  {
    auto curr = A[i];
    if (prev[1] < curr[0])
    {
      count++;
      prev = curr;
    }
  }

  return count;
}