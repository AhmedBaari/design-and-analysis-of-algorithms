#include <iostream>
using namespace std;

void heapsort(int A[], int *count) {
    cout << "Hello World";
};

int main()
{

    int A[5] = {3, 2, 4, 1, 5};

    cout << "\nINPUT: ";
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << ", ";
    }

    int *count = 0;

    heapsort(A, count);
}