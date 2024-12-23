#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
  stack<int> st;
  string s = "363/-63/1-*" ;

  for(int i=0;i<s.length();i++){
    if(isdigit(s[i])){
      st.push(s[i] - '0');
    }
    else{
      int y = st.top();
      st.pop();
      int x = st.top();
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
