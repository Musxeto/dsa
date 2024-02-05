#include <iostream>
#include <climits>

using namespace std;

class MinHeap {
private:
    int* heap;
    int capacity;
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
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] < heap[minIndex]) {
            minIndex = l;
        }

        if (r < size && heap[r] < heap[minIndex]) {
            minIndex = r;
        }

        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->heap = new int[capacity];
    }

    int getMin() {
        if (size == 0) {
            cerr << "Heap is empty. Cannot get minimum element.\n";
            return INT_MIN; // Assuming INT_MIN as a sentinel value for an empty heap
        }
        return heap[0];
    }

    int extractMin() {
        if (size == 0) {
            cerr << "Heap is empty. Cannot extract minimum element.\n";
            return INT_MIN; // Assuming INT_MIN as a sentinel value for an empty heap
        }

        int minElement = heap[0];
        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);

        return minElement;
    }

    void insertKey(int key) {
        if (size == capacity) {
            cerr << "Heap is full. Cannot insert more elements.\n";
            return;
        }

        size++;
        heap[size - 1] = key;
        heapifyUp(size - 1);
    }

    void decreaseKey(int i, int newKey) {
        if (i >= size) {
            cerr << "Index out of bounds.\n";
            return;
        }

        heap[i] = newKey;
        heapifyUp(i);
    }

    void deleteKey(int i) {
        if (i >= size) {
            cerr << "Index out of bounds.\n";
            return;
        }

        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    ~MinHeap() {
        delete[] heap;
    }
};

int main() {
    MinHeap minHeap(10);

    int choice, key, index, newKey;

    do {
        cout << "\nMinHeap Menu:\n";
        cout << "1. Insert Key\n";
        cout << "2. Decrease Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Extract Min\n";
        cout << "5. Print Heap\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                minHeap.insertKey(key);
                break;

            case 2:
                cout << "Enter index and new key: ";
                cin >> index >> newKey;
                minHeap.decreaseKey(index, newKey);
                break;

            case 3:
                cout << "Enter index to delete: ";
                cin >> index;
                minHeap.deleteKey(index);
                break;

            case 4:
                cout << "Min Element: " << minHeap.extractMin() << endl;
                break;

            case 5:
                cout << "Heap elements: ";
                minHeap.printHeap();
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
