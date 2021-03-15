/*
Encode and Decode TinyURL
=========================

Note: This is a companion problem to the System Design problem: Design TinyURL.

TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

class Solution
{
public:
  vector<string> arr;
  // Encodes a URL to a shortened URL.
  string encode(string longUrl)
  {
    arr.push_back(longUrl);
    int size = arr.size();
    string ans = "http://tinyurl.com/" + to_string(size);
    return ans;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl)
  {
    string str = shortUrl.substr(19);
    return arr[stoi(str) - 1];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
