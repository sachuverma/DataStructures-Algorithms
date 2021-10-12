/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:

-1: The number I picked is lower than your guess (i.e. pick < num).
1: The number I picked is higher than your guess (i.e. pick > num).
0: The number I picked is equal to your guess (i.e. pick == num).
Return the number that I picked.

 

Example 1:

Input: n = 10, pick = 6
Output: 6
Example 2:

Input: n = 1, pick = 1
Output: 1 
*/


class Solution {
public:
    int guessNumber(int n) {
        int lo = 1 , hi = n;  
        while(lo <= hi){
            int mid = lo+(hi-lo)/2; 
            if(guess(mid)==0) return mid; 
            else if ( guess(mid) == -1) hi = mid-1; 
            else lo = mid+1; 
        }
        return 0; 
    }
};