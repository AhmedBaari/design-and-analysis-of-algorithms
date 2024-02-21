#include <iostream> // Include the input/output stream library
#include <fstream> // Include the file stream library
#include <stdlib.h> // Include the standard library
#include <time.h> // Include the time library
#include <cstring> // Include the string manipulation library
using namespace std; // Use the standard namespace

int main()
{
    int size[] = {10, 50, 100, 500, 1000, 5000, 10000}; // Define an array of sizes

    for (int i = 0; i < 7; i++) // Iterate over the array of sizes
    {
        char fname[25] = "./random/"; // Define a character array to store the file name
        char ext[2]; // Defin // Define a character array to store the file extensione a character arra(long int)clock()); // Seed the random number generator with the current timefile extension

        srand((long int)clock());  // Null-terminate the file extension/ Seed the random number gen // Get the current size from the arrayerator with the current time

        ext[0] = '1' + i; //  // Concatenate the file extension to the file name with a ".txt" extensionSet the file extension based on t // Create an output file stream with the file namehe current iteration
        ext[1] = '\0'; // Null-terminate the file extension

        int n = size[i]; // Close the output file stream // Get the current size from the array
        strcat(fname, ext); // Concatenate the file extension to the file name
        strcat(fname, ".txt"); // Concatenate the file extension to the file name with a ".txt" extension

        ofstream fout(fname); // Create an output file stream with the file name
        for (int i = 0; i < n; i++) // Generate random numbers and write them to the file
            fout << rand() % (n / 2) << "\t";

        fout.close(); // Close the output file stream
    }
}