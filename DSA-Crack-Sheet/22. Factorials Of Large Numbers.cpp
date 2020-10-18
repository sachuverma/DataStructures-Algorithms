#include<bits/stdc++.h>
using namespace std;

void multiply(vector<int> &res, int &carry, int n){
    int num, digit;
    for(int i=0;i<res.size();++i){
        num = n*res[i] + carry;
        digit = num % 10;
        carry = num /10;
        res[i] = digit;
    }
    while (carry) { 
        int digit = carry%10;
        res.push_back(digit); 
        carry = carry/10; 
    } 
}


int main()
 {
    int t; cin>>t;
    while(t--){
      int no; cin>>no;
      
      vector<int> res(1,1);
      int carry = 0;
    
      for(int i=2;i<=no;++i)
        multiply(res,carry,i);
      
      for(int i=res.size()-1;i>=0;--i)
        cout<<res[i];
      
      cout<<endl;
      
    }
	return 0;
}