#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <limits.h>
using namespace std;

class sort
{
    int a[100000];

public:
    void input(int n, int type)
    {
        char s[100];
        switch (type)
        {
        case 0:
            strcpy(s, "input.txt");
            break;
        case 1:
            strcpy(s, "input-asc.txt");
            break;
        case 2:
            strcpy(s, "input-desc.txt");
            break;
        case 3:
            strcpy(s, "input-equal.txt");
            break;
        }
        ifstream fin(s);
        for (int i = 0; i < n; i++)
        {
            fin >> a[i];
        }
        fin.close();
    }

    void writeOutput(int n, ofstream &fout)
    {
        for (int i = 0; i < n; i++)
            fout << a[i] << " ";
    }

    void merge(int p, int q, int r, int &count)
    {
        int nl, nr, i, j, i1, j1, k;

        nl = q - p + 1;
        nr = r - q;
        int L[nl + 2], R[nr + 2];

        for (i1 = 0; i1 < nl; i1++)
            L[i1] = a[p + i1];
        L[nl] = INT_MAX;

        for (j1 = 0; j1 < nr; j1++)
            R[j1] = a[q + j1 + 1];
        R[nr] = INT_MAX;

        i = 0;
        j = 0;
        for (int k = p; k <= r; k++)
        {
            count++;
            if (L[i] <= R[j])
            {
                a[k] = L[i];
                i++;
            }
            else
            {
                a[k] = R[j];
                j++;
            }
        }

        while (j < nr)
        {
            a[k] = R[j];
            j++;
            k++;
        }

        while (i < nl)
        {
            a[k] = L[i];
            i++;
            k++;
        }
    }

    void mergesort(int p, int r, int &count)
    {
        if (p < r)
        {
            int q = (p + r) / 2;
            mergesort(p, q, count);
            mergesort(q + 1, r, count);
            merge(p, q, r, count);
        }
    }
};

int main()
{
    sort s;
    int arr[] = {100, 1000, 2000, 4000, 5000, 8000, 10000};
    int i, n;
    ofstream fout("output.txt");
    cout << "Random input" << endl;
    for (int i = 0; i < 7; i++)
    {
        int count = 0;
        n = arr[i];
        s.input(n, 0);
        s.mergesort(0, n - 1, count);
        s.writeOutput(n, fout);
        cout << "Input size: " << n << "\t"
             << "No. of Comparisons: " << count << endl;
        fout << "\n";
    }

    cout << "ascending input" << endl;
    for (int i = 0; i < 7; i++)
    {
        int count = 0;
        n = arr[i];
        s.input(n, 1);
        s.mergesort(0, n - 1, count);
        s.writeOutput(n, fout);
        cout << "Input size: " << n << "\t"
             << "No. of Comparisons: " << count << endl;
        fout << "\n";
    }

    cout << "desc input" << endl;
    for (int i = 0; i < 7; i++)
    {
        int count = 0;
        n = arr[i];
        s.input(n, 2);
        s.mergesort(0, n - 1, count);
        s.writeOutput(n, fout);
        cout << "Input size: " << n << "\t"
             << "No. of Comparisons: " << count << endl;
        fout << "\n";
    }

    cout << "Equal input" << endl;
    for (int i = 0; i < 7; i++)
    {
        int count = 0;
        n = arr[i];
        s.input(n, 3);
        s.mergesort(0, n - 1, count);
        s.writeOutput(n, fout);
        cout << "Input size: " << n << "\t"
             << "No. of Comparisons: " << count << endl;
        fout << "\n";
    }
    fout.close();
}