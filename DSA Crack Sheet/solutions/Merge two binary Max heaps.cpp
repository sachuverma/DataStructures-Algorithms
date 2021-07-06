/*
Merge two binary Max heaps
==========================

Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

Example 1:
Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
Explanation :

Your Task:  
You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap.

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n, m <= 105
1 <= a[i], b[i] <= 2*105
*/

void heapify(vector<int> &arr, int idx){
        int n = arr.size();
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        
        if (idx >= n)
        return;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int max;
        
        if (l < n && arr[l] > arr[idx]) max = l;
        else max = idx;
        
        if (r < n && arr[r] > arr[max]) max = r;
      
        if (max != idx) {
            swap(arr[max], arr[idx]);
            heapify(arr, max);
        }
    }
    
    void build_heap(vector<int> &v){
        int n = v.size();
        for(int i=(n/2)-1;i>=0;i--){
            heapify(v,i);
        }
    }     
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> t;
        for(auto &i: b) t.push_back(i);
        for(auto &i: a) t.push_back(i);
        
        build_heap(t);  
        return t;
    }