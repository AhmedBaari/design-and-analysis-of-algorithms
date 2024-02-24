#include <iostream>
#include <math.h>
using namespace std;

// Creating the structures
/* NODE */
struct node
{
    float data;
    node *next;
};

/* HEAD */
struct head
{
    node *first;
    int count;
};

// Creating the bucket class
class bucketsorting {
private:
    head* A[10];

public:
    bucketsorting(){
        for (int i = 0; i < 10;i++) {
            A[i] = new head();
            A[i]->count = 0;
            A[i]->first = NULL;
        }
    }

    void insert_ordered (head* HEAD, float X) {

        // Creating the node
        node *newNode = new node;
        newNode->data = X;
        newNode->next = NULL; // remove this

        /* THE RUNNING PROCESS */
        // Creating the runner and follower
        node *runner;
        node *previous;

        runner = HEAD->first; // First Node
        previous = NULL;

        // If no nodes at all
        if(runner==NULL) {
            HEAD->first = newNode;
            newNode->next = NULL;
        }

        // Find the correct place
        while (runner != NULL && runner->data < X)
        {
           // As long as the runner data stays below the target, we keep running.
           previous = runner;
           runner = runner->next;
        }
        // Correct position is Beginning
        if (previous == NULL) {
            newNode->next = runner; // ^~--B--C
            HEAD->first = newNode;
        } else {
            previous->next = newNode;
            newNode->next = runner;
        }

        (HEAD->count)++;
        }

        void bucketsort (float input_array[], int size) {
            // why 2 stars?
            // head** headarray = new head*[10];

            // For every element in the array
            for (int i = 0; i < size;i++) {
                // Floor function
                int bucket = int(input_array[i] * size);

                // Insert in order
                insert_ordered(A[bucket], input_array[i]);
            }

            /* MAKING THE CONNECTIONS */
            // Appender 'k'
            int k = 0;

            // Run thru first nodes
            for (int i = 0; i < 10; i++) {
                node *runner;

                runner = A[i]->first;
                
                while (runner != NULL) {
                    input_array[k] = runner->data;
                    k++;
                    runner = runner->next;
                }
            }
        }
};

int main()
{
    // Create an instance of the bucketsorting class
    bucketsorting bs;

    // Define an array of floats
    float input_array[] = {0.25, 0.75, 0.1, 0.9, 0.5};

    // Calculate the size of the array
    int size = sizeof(input_array) / sizeof(input_array[0]);

    // Call the bucketsort function
    bs.bucketsort(input_array, size);

    // Print the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << input_array[i] << " ";
    }
    cout << endl;

    return 0;
}