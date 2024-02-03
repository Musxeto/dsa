#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " enqueued to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        cout << temp->data << " dequeued from the queue." << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No element to peek." << endl;
            return -1;
        }

        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue elements: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue myQueue;
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
                myQueue.enqueue(element);
                cout << "Element inserted at the front." << endl;
                system("PAUSE");
                break;

            case 2:
                myQueue.dequeue();
                cout << "Element dequeued from the front." << endl;
                system("PAUSE");
                break;

            case 3:
                cout << (myQueue.isEmpty() ? "Queue is Empty!" : "Queue is not Empty!") << endl;
                system("PAUSE");
                break;

            case 4:
    			cout << "Linked List-based queues don't have a fixed size. The concept of being 'full' is not applicable you dumb nigba." << endl;
    			system("PAUSE");
    			break;


            case 5:
                myQueue.display();
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


