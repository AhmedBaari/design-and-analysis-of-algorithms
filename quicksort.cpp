#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std; 


class quicksort {
private:
    int A[11000];

public:
    void getInput(int n) {
        ifstream fin("./input/random.txt");

        for (int i = 0; i < n;i++) {
            fin >> A[i];
        }

        fin.close();
    }

    int partition(int p, int r, int &count) {
        int x = A[r];

        int i = p-1;

        for (int j = p; j <= r-1; j++) {
            if (A[j] <= x) {
                i++;
                swap(A[i], A[j]);
                count++;
            }
        }
        swap(A[i + 1], A[r]);
        count++;
        return i + 1;
    }

    int randomizedPartition(int p, int r, int &count){
        int random = p + (rand() % (r - p + 1));

        swap(A[random], A[r]);
        return partition(p, r, count);
    }

    void quick_sort(int p, int r, int &count) {
        if (p<r) {
            int q = partition(p,r,count);
            quick_sort(p,q-1,count);
            quick_sort(q+1, r, count);
        }
    } 

    void randomized_quicksort(int p, int r, int &count) {
        if (p<r){
            int q = randomizedPartition(p, r, count);
            randomized_quicksort(p, q - 1, count);
            randomized_quicksort(q + 1, r, count);
        }
    }

    void display(int n,int count) {
        for (int i = 0; i < n; i++) { // Changed i-- to i++
            cout << A[i] << ", ";
        }
        cout << "\nCount: " << count << endl;
    }
};

int main () {
    quicksort S;
    S.getInput(5000);
    int count = 0;
    S.randomized_quicksort(0, 4999, count);
    S.display(5000, count);
}