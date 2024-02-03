#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void displayArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[5] = {2, 3, 4, 7, 1};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Before Sorting: " << endl;
    displayArray(array, n);

    cout << "Heap Sorting: " << endl;
    HeapSort(array, n);
    displayArray(array, n);

    return 0;
}

