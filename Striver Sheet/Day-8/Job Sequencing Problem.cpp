/*
Job Sequencing Problem
======================

Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.

Example 1:
Input:
N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output:
2 60
Explanation:
2 jobs can be done with
maximum profit of 60 (20+40).

Example 2:
Input:
N = 5
Jobs = (1,2,100)(2,1,19)(3,2,27)
(4,1,25)(5,1,15)
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an Integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)

Constraints:
1 <= N <= 100000
1 <= Deadline <= 100
1 <= Profit <= 500
*/

class ComparePQ
{
public:
  bool operator()(Job &a, Job &b)
  {
    return a.profit < b.profit;
  }
};

class Solution
{
public:
  bool static compare(Job &a, Job &b)
  {
    if (a.dead == b.dead)
      return a.profit > b.profit;
    return a.dead > b.dead;
  }

  vector<int> JobScheduling(Job arr[], int n)
  {
    int count = 0, profit = 0;
    sort(arr, arr + n, compare);
    priority_queue<Job, vector<Job>, ComparePQ> pq;

    int deadline = arr[0].dead;
    int i = 0;
    while (i < n)
    {
      deadline = arr[i].dead;
      while (arr[i].dead == deadline)
      {
        pq.push(arr[i]);
        i++;
      }

      int next = 0;
      if (i < n)
        next = arr[i].dead;
      int diff = deadline - next;

      for (int i = 0; i < diff && pq.size(); ++i)
      {
        auto curr = pq.top();
        pq.pop();
        count++;
        profit += curr.profit;
      }
    }
    return {count, profit};
  }
};