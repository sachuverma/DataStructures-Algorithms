/*
Search Suggestions System
=========================

Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

Example 1:
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

Example 2:
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

Example 3:
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

Example 4:
Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]

Constraints:
1 <= products.length <= 1000
There are no repeated elements in products.
1 <= Σ products[i].length <= 2 * 10^4
All characters of products[i] are lower-case English letters.
1 <= searchWord.length <= 1000
All characters of searchWord are lower-case English letters.

Hint #1  
Brute force is a good choice because length of the string is ≤ 1000.

Hint #2  
Binary search the answer.

Hint #3  
Use Trie data structure to store the best three matching. Traverse the Trie.
*/

class Solution
{
public:
  vector<string> binarySearch(vector<string> &prod, string pattern)
  {
    vector<string> ans;
    auto idx = lower_bound(prod.begin(), prod.end(), pattern) - prod.begin();
    int count = 0;
    for (int i = idx; i < prod.size() && count < 3; ++i)
    {
      if (prod[i].substr(0, pattern.size()) != pattern)
        break;
      ans.push_back(prod[i]);
      count++;
    }

    return ans;
  }

  vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
  {
    sort(products.begin(), products.end());
    vector<vector<string>> ans;

    string curr;
    for (auto &i : searchWord)
    {
      curr += i;
      cout << curr << " ";
      ans.push_back(binarySearch(products, curr));
    }

    return ans;
  }
};
