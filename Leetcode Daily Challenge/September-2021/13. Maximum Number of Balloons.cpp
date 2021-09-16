/*
Maximum Number of Balloons
==========================

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:
Input: text = "nlaebolko"
Output: 1

Example 2:
Input: text = "loonbalxballpoon"
Output: 2

Example 3:
Input: text = "leetcode"
Output: 0

Constraints:
1 <= text.length <= 104
text consists of lower case English letters only.

Hint #1  
Count the frequency of letters in the given string.

Hint #2  
Find the letter than can make the minimum number of instances of the word "balloon".
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        
        for(auto& i: text) {
            if(i == 'b') b++;
            else if(i == 'a') a++;
            else if(i == 'l') l++;
            else if(i == 'o') o++;
            else if(i == 'n') n++;
        }
        
        return min({ b, a, l/2, o/2, n });
    }
};