#include <iostream>
using namespace std;

/*
s = current sum
k = current element
r = remaining sum
X --> Mask Array [1,1,0,0]
W --> Subset Array [1,4,3,2]
*/

void sumofsub(int W[], int X[], int current_sum, int k, int remaining_sum, int target_sum)
{

    /* Generate the left child */
    X[k] = 1;

    // Will adding this element give us the target sum?
    if (current_sum + W[k] == target_sum)
    {
        // print
    }

    /* Will adding the next along with this element give us a number lesser than the target */
    else if (current_sum + W[k]+ W[k+1] <= target_sum) {
        // recursively call sumofsub
    }

    /* Generating right child*/
    // Will calling right NOW and left AFTER give me a value matching the condition 
    if ((current_sum + (remaining_sum-W[k]) >= target_sum) && (current_sum + W[k+1] <= target_sum)) {
        // Set x[k] = 0 
        // Call recursively.

    }
}