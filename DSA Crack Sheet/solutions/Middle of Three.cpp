/*
Middle of Three
===============

Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).

Example 1:
Input:
A = 978, B = 518, C = 300
Output:
518
Explanation:
Since 518>300 and 518<978, so 
518 is the middle element.

Example 2:
Input:
A = 162, B = 934, C = 200
Output:
200
Exaplanation:
Since 200>162 && 200<934,
So, 200 is the middle element.

Your Task:
You don't need to read input or print anything.Your task is to complete the function middle() which takes three integers A,B and C as input parameters and returns the number which has middle value.

Expected Time Complexity:O(1)
Expected Auxillary Space:O(1)

Constraints:
1<=A,B,C<=109
A,B,C are distinct. 
*/

int middle(int A, int B, int C)
{
  //code here//Position this line where user code will be pasted.
  if (A > B)
  {
    if (C > A)
      return A;
    else if (C < A && B > C)
      return B;
    else
      return C;
  }
  else
  {
    if (C > B)
      return B;
    else if (C < B && A > C)
      return A;
    else
      return C;
  }
}
