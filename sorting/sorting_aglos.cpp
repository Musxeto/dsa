#include<iostream>
using namespace std;

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        swap(A[i], A[minIndex]);
    }
}

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub - lb + 1];

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k - lb] = a[i];
            i++;
        } else {
            b[k - lb] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k - lb] = a[i];
        i++;
        k++;
    }

    while (j <= ub) {
        b[k - lb] = a[j];
        j++;
        k++;
    }

    for (int x = lb; x <= ub; x++) {
        a[x] = b[x - lb];
    }
}

void mergeSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(A, lb, mid);
        mergeSort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}

int partition(int A[], int lb, int ub) {
    int Pivot = A[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (A[start] <= Pivot) {
            start++;
        }
        while (A[end] > Pivot) {
            end--;
        }

        if (start < end) {
            swap(A[start], A[end]);
        }
    }
    swap(A[lb], A[end]);
    return end;
}


void QuickSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int Part = partition(A, lb, ub);
        QuickSort(A, lb, Part - 1);
        QuickSort(A, Part + 1, ub);
    }
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

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

    cout << "Selection Sorting: " << endl;
    selectionSort(array, n);
    displayArray(array, n);

    cout << "Insertion Sorting: " << endl;
    insertionSort(array, n);
    displayArray(array, n);

    cout << "Bubble Sorting: " << endl;
    bubbleSort(array, n);
    displayArray(array, n);

    cout << "Merge Sorting: " << endl;
    mergeSort(array, 0, n - 1);
    displayArray(array, n);
	
	cout << "Quick Sorting: " << endl;
    QuickSort(array, 0, n - 1);
    displayArray(array, n);
	
	cout << "Heap Sorting: " << endl;
    heapSort(array, n);
    displayArray(array, n);
    return 0;
}

