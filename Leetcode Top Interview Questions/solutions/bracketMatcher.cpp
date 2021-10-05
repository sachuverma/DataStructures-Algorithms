
#include <bits/stdc++.h>

using namespace std;

string BracketMatcher(string str) {
  
  // code goes here  
  stack<char> s;

  for(int i=0; i<str.length(); i++){
    if(str[i] == '(')
       s.push(str[i]);

    if(str[i] == ')' ){
      if(!s.empty())
         s.pop();
      else return "0";
    }   
  }
  
  return s.empty() ? "1" : "0";

}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout << BracketMatcher("(hello (world))");

    return 0;    

}