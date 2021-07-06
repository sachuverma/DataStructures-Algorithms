/*
Minimum sum
===========

Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.

Example 1:
Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.

Example 2:
Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.

Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes arr[] and n as input parameters and returns the minimum possible sum. As the number can be large, return string presentation of the number without leading zeroes.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 107
0 ≤ Arri ≤ 9
*/

string add(string str1, string str2)
{
  if (str1.length() > str2.length())
    swap(str1, str2);

  string str = "";

  int n1 = str1.length(), n2 = str2.length();

  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());

  int carry = 0;
  for (int i = 0; i < n1; i++)
  {
    int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
    str.push_back(sum % 10 + '0');

    carry = sum / 10;
  }

  for (int i = n1; i < n2; i++)
  {
    int sum = ((str2[i] - '0') + carry);
    str.push_back(sum % 10 + '0');
    carry = sum / 10;
  }

  if (carry)
    str.push_back(carry + '0');

  reverse(str.begin(), str.end());
  return str;
}

string solve(int arr[], int n)
{

  if (n == 1)
    return to_string(arr[0]);
  sort(arr, arr + n);
  string s1, s2;

  int i = 0;
  int j = 1;
  while (j < n && arr[j] == 0)
  {
    i++;
    j++;
  }
  if (j >= n)
  {
    return to_string(arr[i]);
  }
  if (arr[i] == 0)
  {
    i++;
    j++;
  }
  while (j < n)
  {
    s1.push_back('0' + arr[i]);
    s2.push_back('0' + arr[j]);
    i += 2;
    j += 2;
  }
  if (i == n - 1)
  {
    s1.push_back('0' + arr[i]);
    reverse(s2.begin(), s2.end());

    s2.push_back('0');
    reverse(s2.begin(), s2.end());
  }
  return add(s1, s2);
}