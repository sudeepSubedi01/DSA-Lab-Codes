#include<iostream>
using namespace std;
#define n 100

template<class T>

class Stack{
  T* arr; 
  int top;

  public:
  Stack(){
    arr = new T[n];
    top = -1;
  }

  ~Stack(){
    delete [] arr;
  }

  void push(T x){
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
    cout<<endl;
  }

};

int main(){
  Stack<int> st;
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

  // Using Stack with string type
  Stack<double> st_double;
  st_double.push(1.1);
  st_double.push(2.2);
  st_double.push(3.3);
  st_double.display_stack();

  // Using Stack with string type
  Stack<string> st_string;
  st_string.push("Stack");
  st_string.push("Implementation");
  st_string.push("using Template Class");
  st_string.display_stack();
}