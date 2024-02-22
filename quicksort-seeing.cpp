#include <iostream>
#include <fstream>
#include <limits.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

class quick_sort
{
private:
    long int A[11000];

public:
    void readInput(int n)
    {
        ifstream fin("./input/random.txt");

        for (int i = 0; i < n; i++)
        {
            fin >> A[i];
        }
        fin.close();
    }
    void writeOutput(int n)
    {
        ofstream fout("./output/random.txt");

        for (int i = 0; i < n; i++)
        {
            fout << A[i];
        }
        fout.close();
    }

    int partition(int p, int r, int &count)
    {
        int x = A[r];

        int i = p - 1;
        int j;
        for (j = p; j <= r - 1; j++)
        {
            // count
            count++;
            if (A[i] <= x)
            {

                // Swap
                swap(A[i], A[j]);

                // Possible point issue to X
            }
        }
        count++;

        // Final Swap
        swap(A[i + 1], A[j]);
        return (i + 1);
    }

    void quicksort(int p, int r, int &count)
    {
        if (p < r)
        {
            //🔴🔴 EXTREME
            int q = partition(p, r, count);
            quicksort(p, q - 1, count);
            quicksort(q + 1, r, count);
        }
    }
    void display(int n)
    {
        for (int i = 0; i < n; i++)
            cout <<A[i] << " ";
        cout << endl;
    }
};

int main()
{
    cout << "Hello World";

    quick_sort s;

    int n = 20;
    int count = 0;
    s.readInput(n);
    cout << "\nbefore sorting: ";
    s.display(n);

    s.quicksort(0, n - 1, count);

    cout << "\nafter sorting: ";
    s.display(n);
}
