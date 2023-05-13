#include <iostream>
using namespace std;
int rarray[100];
int larray[100];
void merge(int A[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int larray[n1], rarray[n2];

    for (i = 0; i < n1; i++)
        larray[i] = A[beg + i];
    for (j = 0; j < n2; j++)
        rarray[j] = A[mid + 1 + j];

    i = 0;
    j = 0;
    k = beg;

    while (i < n1 && j < n2)
    {
        if (larray[i] <= rarray[j])
        {
            A[k] = larray[i];
            i++;
        }
        else
        {
            A[k] = rarray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = larray[i];
        i++;
        k++;
    }
    while (i < n2)
    {
        A[k] = rarray[j];
        j++;
        k++;
    }
}
void mergesort(int A[], int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        mergesort(A, beg, mid);
        mergesort(A, mid + 1, end);
        merge(A, beg, mid, end);
    }
}

int main()
{
    int A[] = {12, 11, 13, 5, 6, 7};
    mergesort(A, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << A[i] << " ";
    }
}