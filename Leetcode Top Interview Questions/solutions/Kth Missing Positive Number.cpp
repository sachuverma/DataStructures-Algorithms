/*
Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Find the kth positive integer that is missing from this array.

Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

Constraints:
- 1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]-mid-1<k)
                s=mid+1;
            else
                e=mid-1;
        }
        return (k+s);
    }
};
