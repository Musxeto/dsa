#include<iostream>

using namespace std;

class CircularQueue {
public:
    static const int SIZE = 5;
    int arr[SIZE];
    int rear = -1;
    int front = -1;

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            system("PAUSE");
            return;
        } else if (isEmpty()) {
            rear = front = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << "Element inserted at the front." << endl;
        system("PAUSE");
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            cout << arr[front] << " is dequeued!" << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
        }
        system("PAUSE");
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
        cout << endl;
    }
};

int main() {
    CircularQueue circularQueue;
    int choice, element;

    do {
        system("CLS");

        cout << "\nMain Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check For Empty" << endl;
        cout << "4. Check For Full" << endl;
        cout << "5. Display Queue" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> element;
                circularQueue.enqueue(element);

                break;

            case 2:
                circularQueue.dequeue();
                break;

            case 3:
                cout << (circularQueue.isEmpty() ? "Queue is Empty!" : "Queue is not Empty!") << endl;
                system("PAUSE");
                break;

            case 4:
                cout << (circularQueue.isFull() ? "Queue is Full!" : "Queue is not Full!") << endl;
                system("PAUSE");
                break;

            case 5:
                circularQueue.display();
                system("PAUSE");
                break;

            case 0:
                cout << "Exiting the program." << endl;
                system("PAUSE");
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                system("PAUSE");
        }
    } while (choice != 0);

    return 0;
}

