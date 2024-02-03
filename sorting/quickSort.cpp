#include<iostream>
using namespace std;

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
	
	cout << "Quick Sorting: " << endl;
    QuickSort(array, 0, n - 1);
    displayArray(array, n);
	
    return 0;
}

