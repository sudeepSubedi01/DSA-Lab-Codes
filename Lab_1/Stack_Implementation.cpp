#include<iostream>
using namespace std;
#define n 100

class Stack{
  int* arr; 
  int top;

  public:
  Stack(){
    arr = new int[n];
    top = -1;
  }

  ~Stack(){
    delete [] arr;
  }

  void push(int x){
    if (top == n-1){
      cout<<"Stack Overflow"<<endl;
      return; 
    }
    top++;
    arr[top] = x;
  }

  void pop(){
    if (top == -1){
      cout<<"No elements in stack to pop"<<endl;
      return;
    }
    top--;
  }

  void peek(){
    if (top == -1){
      cout<<"Stack is empty, nothing to peek"<<endl;
      return;
    }
    cout<<"Element at the top: "<<arr[top]<<endl;
  }

  bool isEmpty(){
    return top == -1;
  }

  void display_stack(){
    if (top == -1){
      cout<<"Stack is empty"<<endl;
      return;
    }
    
    cout<<"All Stack Elements: ";
    for (int i=0; i<=top; i++){
      cout<<arr[i]<<' ';
    } 
  }

};

int main(){
  Stack st;
  st.push(11);
  st.push(22);
  st.push(33);
  st.peek();

  st.pop();
  st.peek();

  cout<<st.isEmpty()<<endl;

  st.peek();
  cout<<st.isEmpty()<<endl;

  st.push(111);
  st.push(222);
  st.push(333);
  st.display_stack();

}