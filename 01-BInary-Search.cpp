#include <iostream>
using namespace std;
int Bs(int A[], int l, int h, int key)
{
    int mid;
    if (l == h)
    {
        if (A[l] == key)
            return l;
        else
            return 0;
    }
    else
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        if (key < A[mid])
            return Bs(A, l, mid - 1, key);
        else
            return Bs(A, mid + 1, h, key);
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int result = Bs(A, 0, 6, 7);
    if (result == 0)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index " << result << endl;
    }
    return 0;
}