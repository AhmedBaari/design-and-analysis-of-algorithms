#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void countsort(int A[], int B[], int n, int k)
{
    int count = 0;
    int *C = new int[k + 1]; // Increase the size of C array by 1

    // Initialize C array with 0
    for (int i = 0; i <= k; i++)
    {
        C[i] = 0;
        count++;
    }

    // Count the occurrences of each element in A
    for (int j = 0; j < n; j++)
    {
        C[A[j]]++;
        count++;
    }

    // Calculate the cumulative sum of counts in C
    for (int i = 1; i <= k; i++)
    {
        C[i] += C[i - 1];
        count++;
    }

    // Place the elements from A into B in sorted order
    for (int j = n - 1; j >= 0; j--)
    {
        B[C[A[j]]] = A[j]; 
        C[A[j]]--;
        count++;
    }

    // Display the sorted array B
    for (int i = 1; i < n+1; i++)
    {
        cout << B[i] << " | ";
    }
    cout << "\nCOUNT: " << count << endl;

    cout << "\n";

}

void radixsort(int A[], int n, int maxDigit)
{
    // Create a temporary array to hold the digit values
    int *B = new int[n];

    // Do counting sort for every digit
    for (int exp = 1; maxDigit/exp > 0; exp *= 10)
    {
        // Extract the digit values and store them in B
        for (int i = 0; i < n; i++)
        {
            B[i] = (A[i]/exp)%10;
        }

        // Call counting sort on B
        countsort(B,A, n,9);


    }

    delete[] B;
}



int main()
{
    cout << "Hello World" << endl;

    int n = 5;
    ifstream fin("./input/random.txt");
    int *A = new int[n];
    int *B = new int[n];

    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        fin >> A[i];
        largest = A[i] > largest ? A[i] : largest;
    }

    int k = largest;
    countsort(A, B, n, k);


    return 0;
}