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
        return (rear + 1) % size == front;
    }

    int getSize() {
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
            rear = (rear + 1) % size;
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
                front = (front + 1) % size;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i != (rear + 1) % size; i = (i + 1) % size) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue niceYar;
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
            niceYar.enqueue(element);
            cout << "Element inserted at the front." << endl;
            system("PAUSE");
            break;

        case 2:
            niceYar.dequeue();
            cout << "Element dequeued from the front." << endl;
            system("PAUSE");
            break;

        case 3:
            cout << (niceYar.isEmpty() ? "Queue is Empty!" : "Queue is not Empty!") << endl;
            system("PAUSE");
            break;

        case 4:
            cout << (niceYar.isFull() ? "Queue is Full!" : "Queue is not Full!") << endl;
            system("PAUSE");
            break;

        case 5:
            niceYar.display();
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

