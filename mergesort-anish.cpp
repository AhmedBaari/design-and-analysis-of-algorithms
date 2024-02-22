#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void merge(int a[], int p, int q, int r)
{

    int n1, n2;
    n1 = q - p + 1;
    n2 = r - q;

    int L[n1 + 1], R[n2 + 1], i, j, k;

    for (i = 0; i < n1; i++)
    {
        L[i] = a[p + i];
    }
    L[n1] = 99999;

    for (j = 0; j < n2; j++)
    {
        R[j] = a[q + j+1];
    }
    R[n2] = 99999;

    i = 0;
    j = 0;

    for (k = p; k <= r; k++)
    {
        if (L[i] < R[j])
        {
            a[k] = L[i];
            i += 1;
        }
        else
        {
            a[k] = R[j];
            j += 1;
        }
    }
}

void mergesort(int a[], int p, int r)
{

    if (p < r)
    {
        int q;
        q = (p + r) / 2;
        mergesort(a, p, q);
        mergesort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

int main()
{
    // Initial Array
    int a[10] = {1, 5, 4, 2, 3,10,7,9,6,8};

    // Calling mergesort
    mergesort(a, 0, 9);

    // Final Array
    cout << "\nFinal Array: ";
    for (int i = 0; i < 10; i++) {
        cout << a[i] << ", ";
    }
}