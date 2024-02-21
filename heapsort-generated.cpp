/*
Ahmed Baari - 126156004 - F02 - DAA Lab of semester 4
TOPIC: HEAP SORT
*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)



void max_heapify(int arr[], int i, int n, int &count)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    count++;
    int largest, temp;

    if (l <= arr[0] && arr[l] > arr[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    count = count + 1;

    if (r <= arr[0] && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, largest, n, count);
    }
}

void build_maxheap(int arr[], int &count, int n)
{
    arr[0] = n;
    for (int i = n / 2; i >= 1; i--)
    {
        max_heapify(arr, i, n, count);
    }
}

void heapsort(int arr[], int n, int &count)
{
    build_maxheap(arr, count, n);
    int temp;

    for (int i = arr[0]; i >= 2; i--)
    {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        arr[0]--;
        max_heapify(arr, 1, n, count);
    }
}

void input(int arr[], int n, int type)
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
        fin >> arr[i];
    fin.close();
}

void writeOutput(int arr[], int n, ofstream &fout)
{
    for (int i = 0; i < n; i++)
        fout << arr[i] << "\t";
}

int main()
{
    int arr[1000000];
    int count = 0;
    int inputSizes[] = {100, 1000, 2000, 4000, 5000, 8000, 10000};
    int numInputSizes = sizeof(inputSizes) / sizeof(inputSizes[0]);

    ofstream fout("output.txt");

    cout << "Random input" << endl;
    for (int i = 0; i < numInputSizes; i++)
    {
        count = 0;
        int n = inputSizes[i];
        input(arr, n, 0);
        heapsort(arr, n, count);
        writeOutput(arr, n, fout);
        cout << "Input size: " << n << "\t"
             << "No. of Comparisons: " << count << endl;
        fout << "\n";
    }

    cout << "Ascending input" << endl;
    for (int i = 0; i < numInputSizes; i++)
    {
        count = 0;
        int n = inputSizes[i];
        input(arr, n, 1);
        heapsort(arr, n, count);
        writeOutput(arr, n, fout);
        cout << "Input size: " << n << "\t"
             << "No. of Comparisons: " << count << endl;
        fout << "\n";
    }

    cout << "Descending input" << endl;
    for (int i = 0; i < numInputSizes; i++)
    {
        count = 0;
        int n = inputSizes[i];
        input(arr, n, 2);
        heapsort(arr, n, count);
        writeOutput(arr, n, fout);
        cout << "Input size: " << n << "\t"
             << "No. of Comparisons: " << count << endl;
        fout << "\n";
    }

    cout << "Equal input" << endl;
    for (int i = 0; i < numInputSizes; i++)
    {
        count = 0;
        int n = inputSizes[i];
        input(arr, n, 3);
        heapsort(arr, n, count);
        writeOutput(arr, n, fout);
        cout << "Input size: " << n << "\t"
             << "No. of Comparisons: " << count << endl;
        fout << "\n";
    }

    fout.close();

    return 0;
}
