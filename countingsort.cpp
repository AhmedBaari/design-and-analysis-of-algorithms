#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countsort(int A[], int B[], int n, int k)
{
    int count = 0;
    // C array has counts of all the elements
    int *C = new int[k];
    for (int i = 0; i < k; i++)
    {
        C[i] = 0;
        count = count + 1;
    }

    // Now let's put the counts
    for (int j = 0; j < n; j++)
    {

        C[A[j]] = C[A[j]] + 1;
        count = count + 1;
    }

    // Let's make it a progressive sum
    for (int i = 0; i < k; i++)
    {
        C[i] = C[i - 1] + C[i];
        count = count + 1;
    }

    // Let's put it in B array
    for (int j = n - 1; j >= 0; j--)
    {
 //cse4b60
        C[A[j]] = C[A[j]] - 1;
        count = count + 1;
    }
    // Let's display it
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " | ";
    }
    cout << "\nCOUNT: " << count << endl;

    cout << "\n";
}

int main()
{
    cout << "Hello World" << endl;

    // int A[6] = {3,5,2,2,1,6};

    int n = 5;
    ifstream fin("./input/random.txt");
    int *A = new int[n + 1];
    int B[n + 1];

    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        fin >> A[i];
        largest = A[i] > largest ? A[i] : largest;
    }

    int k = largest;
    countsort(A, B, n, k);
}