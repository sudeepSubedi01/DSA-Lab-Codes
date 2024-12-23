#include<iostream>
#include<stack>
#include<string>
#include <bits/stdc++.h>
using namespace std;

int main(){
  stack<int> st;
  string s = "*-3/63-/631";
  reverse(s.begin(),s.end());

  for(int i=0;i<s.length();i++){
    if(isdigit(s[i])){
      st.push(s[i] - '0');
    }
    else{
      int x = st.top();
      st.pop();
      int y = st.top();
      st.pop();

      switch(s[i]){
        case '+':
          st.push(x+y);
          break;
        case '-':
          st.push(x-y);
          break;
        case '*':
          st.push(x*y);
          break;
        case '/':
          st.push(x/y);
          break;
      }
    }
  }
  cout<<"Result: "<<st.top()<<endl;
  return 0;
}
