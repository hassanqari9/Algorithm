#include <iostream>

using namespace std;

int j;

int partition(int A[], int l, int h) {
    int i = l;
    j = h;
    int pivot = A[l];

    while (i < j) {
        do {
            i++;
        } while (A[i] < pivot);

        do {
            j--;
        } while (A[j] > pivot);

        if (i < j)
            swap(A[i], A[j]);
    }

    swap(A[l], A[j]);
    return j;
}

void quicksort(int A[], int l, int h) {
    if (l < h) {
        j = partition(A, l, h);
        quicksort(A, l, j);
        quicksort(A, j + 1, h);
    }
}

int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    quicksort(A, 0, 6);

    for (int i = 0; i < 6; i++) {
        cout << A[i] << " ";
    }

    return 0;
}