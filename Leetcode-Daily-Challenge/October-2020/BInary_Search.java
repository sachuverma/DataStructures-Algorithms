class Solution {
        public int search(int[] nums, int target) {
            int low=0;
            int high=nums.length-1;
            
            while(low<=high){
                int m=(low+high)/2;
                if(target<nums[m]){
                    high=m-1;
                } else if(nums[m]<target){
                    low=m+1;
                } else {
                    return m;
                }
            }
            return -1;
        }
    }

