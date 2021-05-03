/*
Find MSB In O(1)
================

Problem Statement
You are given a positive integer N. Your task is to find the greatest integer less than or equal to N which is a power of 2.

For Example:
If N = 14,
The nearest integer that is less than or equal to 14 and is a power of two is 8(2^3). So, the answer is 8.

Follow Up:
Can you solve this in constant time and space complexity?

Input Format:
The first line contains an integer 'T' which denotes the number of test cases. Then, the T test cases follow.
The first and only line of each test case contains a single integer N.

Output Format:
For each test case, print the nearest integer that is less than or equal to N and also is a power of 2.
Output for each test case will be printed in a separate line.

Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.

Constraints:
1 <= T <= 2000
1 <= N <= 10^9

Time limit: 1 second
Sample Input 1:
2
4
22

Sample Output 1:
4
16
Explanation For Sample 1:
For the first test case, 4 itself is a power of two.
For the second test case, the nearest integer that is less than or equal to 22 and also is a power of two is 16.

Sample Input 2:
2
1
63

Sample Output 2:
1
32
*/

int findMSB(int n)
{
  n = n | n >> 1;
  n = n | n >> 2;
  n = n | n >> 4;
  n = n | n >> 8;
  n = n | n >> 16;

  n = n + 1;
  return (n >> 1);
}
