#include<iostream>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

int precedence(char c){
  if (c == '^'){
    return 3;
  }
  else if(c == '*' || c == '/'){
    return 2;
  }
  else if(c == '+' || c == '-'){
    return 1;
  }
  else{
    return -1;
  }
}
string Convert(string s){
  stack<char> st;
  string res;
  reverse(s.begin(), s.end());
  for (int i=0; i< s.length(); i++){
    if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
      res = res + s[i];
    }
    else if(s[i] == ')'){
      st.push(s[i]);
    }
    else if(s[i] == '('){
      while( !st.empty() && st.top() != ')'){
        res += st.top();
        st.pop();
      }
      if(!st.empty()){
        st.pop();
      }
    }
    else{
      while(!st.empty() && ( precedence(st.top()) > precedence(s[i]))){
        res = res + st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }
  while(!st.empty()){
    res = res + st.top();
    st.pop();
  }
  reverse(res.begin(), res.end());
  return res;
}
int main(){
  cout<<Convert("(A-B/C)*(P/Q-R)")<<endl;
  return 0;
}