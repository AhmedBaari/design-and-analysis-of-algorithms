#include <iostream>
#include <fstream>
# include <string>
using namespace std;

void merge(int A[], int p, int q, int r, int *count)
{
    // Sizes of the arrays
    int m = q - p + 1;
    int n = r - q;

    // Creating subarrays
    int left[m + 1];
    int right[n + 1];

    // Assigning Values
    for (int i = 0; i < m; i++)
    {
        left[i] = A[p + i];
        cout << left[i] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        right[i] = A[q + i + 1];
        cout << right[i] << " ";
    }

    // infinite values
    left[m] = 999999;
    right[n] = 999999;

    int i = 0;
    int j = 0;
    // Merging
    for (int k = p; k <= r; k++)
    {
        if (left[i] < right[j])
        {
            A[k] = left[i];
            i = i + 1;
        }
        else
        {
            A[k] = right[j];
            j = j + 1;
        }
    }
}

void mergesort(int A[], int p, int r, int *count)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(A, p, q, count);
        mergesort(A, q + 1, r, count);
        merge(A, p, q, r, count);
    }
}

int main()
{
    cout << "Hello World";

    for (int i = 1; i < 8;i++){
        string path = "./random/" + to_string(i) + ".txt";

        cout << "File: " << path << endl;

        fstream myFile(path);
        if (!myFile) {
            cout << "Error opening file";
        }

        int num;
        
    };
        

    int A[5] = {5, 3, 2, 4, 1};
    int *count;
    count = 0;
    mergesort(A, 0, 4, count);

    cout << "SORTED: ";
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << ", ";
    }
}