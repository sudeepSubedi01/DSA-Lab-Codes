#include <iostream>
using namespace std;

class LinearQueue {
private:
    int *arr;
    int front, rear, capacity;

public:
    LinearQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~LinearQueue() {
        delete[] arr;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << "Enqueued " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued " << arr[front] << endl;
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearQueue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.display();

    queue.enqueue(60);

    queue.dequeue();
    queue.dequeue();

    queue.display();

    return 0;
}
