#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void randomInput() {
    ofstream fout("./input/random.txt");

    srand((long int)clock());

    for (int i = 0; i < 10000; i++) { 
        fout << rand() % 30000 << "\t";
    }


    fout.close();
}

// Ascending Input
void ascendingInput() {
    ofstream fout("./input/ascending.txt");

    srand((long int)clock());

    for (int i = 0; i < 10010; i++) {
        fout << i << "\t";
    }

    fout.close();
}

// Descending Input 
void descendingInput () {
    ofstream fout("./input/descending.txt");

    for (int i = 10009; i > 0; i--) {
        fout << i << "\t";
    }
    fout.close();
}

// Descending Input
void equalInput()
{
    ofstream fout("./input/equal.txt");

    for (int i = 10009; i > 0; i--)
    {
        fout << 1 << "\t";
    }
    fout.close();
}

int main()
{
    randomInput();
    ascendingInput();
    descendingInput();
    equalInput();
    return 0;
}
