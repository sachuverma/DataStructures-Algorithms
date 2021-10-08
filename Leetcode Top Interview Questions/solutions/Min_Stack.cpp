 #include<bits/stdc++.h>
 using namespace std;

 stack<int>s;
 stack<int>t;

 void push(int val) {
    s.push(val);
    if(t.empty())
        t.push(val);
    else{
        if(val<t.top())
            t.push(val);
        else
            t.push(t.top());
        }
    }

 void pop() {
        s.pop();
        t.pop();
    }

 int top() {
        return s.top();
    }

 int getMin() {
        if(t.empty())
            return -1;
        return t.top();
    }

 int main(){
      cout<<"This program is used to find minimum value from stacks at any time without traversing stack\n\n";

      cout<<"Enter number of Elements to push in stacks";
      int n;
      cin>>n;

      for(int i=0;i<n;i++){
        int num;
        cin>>num;
        push(num);
      }

      cout<<"The current minimum is : "<<getMin()<<endl;

      cout<<"The top element is : "<<top()<<endl;

      pop();
      pop();

       cout<<"The current minimum is : "<<getMin()<<endl;





 }









