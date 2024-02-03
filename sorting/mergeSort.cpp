#include<iostream>
using namespace std;

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

void displayArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int array[5] = {2, 3, 4, 7, 1};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Before Sorting: " << endl;
    displayArray(array, n);

    cout << "Merge Sorting: " << endl;
    mergeSort(array, 0, n - 1);
    displayArray(array, n);

    return 0;
}

