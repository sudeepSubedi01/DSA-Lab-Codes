#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int arr[MAX]; 
    int top;

public:
    Stack() { 
        top = -1; 
    }

    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed into the stack." << endl;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! No element to pop." << endl;
        } else {
            cout << arr[top] << " popped from the stack." << endl;
            top--;
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return (top < 0);
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60); 

    s.display();

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    s.display();

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
