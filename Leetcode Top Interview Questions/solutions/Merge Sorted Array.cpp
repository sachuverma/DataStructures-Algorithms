/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

*/


#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int i=m-1,j=n-1,k=m+n-1;
    while(i>=0&&j>=0)
    {
        if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }
        else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
    while(i>=0)
            nums1[k--]=nums1[i--];
    while(j>=0)
            nums1[k--]=nums2[j--];
}
int main(){
    int n,m;
    cout<<"Enter Length of two arrays: ";

    cin>>n>>m;
    vector<int>nums1(n+m),nums2(m);

    cout<<"Enter values in first array";
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }

    cout<<"Enter values in second array";
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }

    merge(nums1,n,nums2,m);
    cout<<"The Merged Sorted arrays are: ";
    for(int i=0;i<n+m;i++){
        cout<<nums1[i]<<" ";
        }
    return 0;
}
