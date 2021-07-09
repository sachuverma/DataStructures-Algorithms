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
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/

bool static compare(Job &a, Job &b)
{
  return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
  int count = 0, profit = 0;
  sort(arr, arr + n, compare);

  // we will try to fill empty solts for each job
  int slot[n] = {0};

  for (int i = 0; i < n; ++i)
  {
    for (int j = min(n, arr[i].dead) - 1; j >= 0; --j)
    {
      if (slot[j] == 0)
      {
        count++;
        profit += arr[i].profit;
        slot[j] = 1;
        break;
      }
    }
  }

  return {count, profit};
}