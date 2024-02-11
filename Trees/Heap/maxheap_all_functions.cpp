#include <iostream>

using namespace std;

class MaxHeap {
private:
    static const int MAX_SIZE = 100;
    int heap[MAX_SIZE];
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] > heap[maxIndex]) {
            maxIndex = l;
        }

        if (r < size && heap[r] > heap[maxIndex]) {
            maxIndex = r;
        }

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    MaxHeap() : size(0) {}

    int getMax() {
        if (size == 0) {
            cout << "Heap is empty. Cannot get the maximum element.\n";
            return -1; // Assuming -1 as a sentinel value for an empty heap
        }
        return heap[0];
    }

    int extractMax() {
        if (size == 0) {
            cout << "Heap is empty. Cannot extract the maximum element.\n";
            return -1; // Assuming -1 as a sentinel value for an empty heap
        }

        int maxElement = heap[0];
        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);

        return maxElement;
    }

    void insertKey(int key) {
        if (size == MAX_SIZE) {
            cout << "Heap is full. Cannot insert more elements.\n";
            return;
        }

        size++;
        heap[size - 1] = key;
        heapifyUp(size - 1);
    }

    void increaseKey(int i, int newKey) {
        if (i >= size) {
            cout << "Index out of bounds.\n";
            return;
        }

        heap[i] = newKey;
        heapifyUp(i);
    }

    void deleteKey(int i) {
        if (i >= size) {
            cout << "Index out of bounds.\n";
            return;
        }

        increaseKey(i, INT_MAX);
        extractMax();
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;

    int choice, key, index, newKey;

    do {
        cout << "\nMaxHeap Menu:\n";
        cout << "1. Insert Key\n";
        cout << "2. Increase Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Extract Max\n";
        cout << "5. Print Heap\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                maxHeap.insertKey(key);
                break;

            case 2:
                cout << "Enter index and new key: ";
                cin >> index >> newKey;
                maxHeap.increaseKey(index, newKey);
                break;

            case 3:
                cout << "Enter index to delete: ";
                cin >> index;
                maxHeap.deleteKey(index);
                break;

            case 4:
                cout << "Max Element: " << maxHeap.extractMax() << endl;
                break;

            case 5:
                cout << "Heap elements: ";
                maxHeap.printHeap();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;
}
