// { Driver Code Starts
// driver code

#include<bits/stdc++.h>
using namespace std;

string LongestPalindromeSubString(string text);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<< LongestPalindromeSubString(s) << endl;
    }
    return 1;
}
// } Driver Code Ends


// return the longest palindrome substring

string LongestPalindromeSubString(string text)
{
    // code here
    string h="#";
   for(int i=0;i<text.size();i++){
       h.push_back(text[i]);
       h.push_back('#');
   }

   int C=-1;
   int R=-1;
   int n=h.size();
   vector<int>lps(n);
   int imirror;

   for(int i=0;i<n;i++){
       imirror=2*C-i;
       if(R>i){
           lps[i]=min(R-i,lps[imirror]);
       }
       else{
           lps[i]=0;
       }

       while((i-lps[i]-1)>=0 && (i+lps[i]+1)<n && h[i-lps[i]-1]==h[i+1+lps[i]]){
           lps[i]++;
       }
       if(i+lps[i]>R){
           R=i+lps[i];
           C=i;
       }
   }

   int mx=0;
   int s;
   for(int i=0;i<n;i++){
       if(mx<lps[i]){
           s=i;
           mx=lps[i];
       }
   }
   int l=s-mx;
   int r=s+mx;
   string h2=h.substr(l,r-l+1);
   string ans="";
   for(int i=0;i<h2.size();i++){
       if(h2[i]!='#'){
           ans.push_back(h2[i]);
       }
   }
   return ans;



}
