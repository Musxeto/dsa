#include<iostream>

using namespace std;

class Queue {
public:
    static const int size = 5;
    int array[size];
    int front = -1;
    int rear = -1;

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return rear == size - 1;
    }

    int count() {
        return rear - front + 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Already Full Blud!!!" << endl;
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear++;
        }
        array[rear] = val;
        cout << val << " entered at rear!" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Shit ain't in here blud, what you wanna delete dumb ah!" << endl;
            return;
        }
        else {
            cout << array[front] << " is Dequeued!" << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else {
                front++;
            }
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);

    return 0;
}

