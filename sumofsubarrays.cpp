#include <iostream>
using namespace std;

/*
s = current sum
k = current element
r = remaining sum 
X --> Mask Array [1,1,0,0]
W --> Subset Array [1,4,3,2]
*/

void sumofsub(int W[], int X[], int current_sum,int k,int remaining_sum, int target_sum) {
	
	/* GENERATING LEFT CHILD */
	X[k] = 1; // [1,0,0,0]
	
	// Will adding this element give us the target sum?
	if (current_sum + W[k] == target_sum) { // 0 + 1 = 5 ??
		for( int i = 0 ; i < k+1; i++ ) { // It is a solution!!
			cout << X[i] << "-";
		}
		cout << endl;
	}
	
	// Will adding the next element keep us below or equal to the target sum?
	else if (current_sum + W[k] + W[k+1] <= target_sum) {
		// Recursively call sumofsub
		cout << "Calling LEFT with " << k+1 << " = TRUE" << endl;
		sumofsub(W,X, (current_sum + W[k]), k+1, (remaining_sum-W[k]), target_sum);
	}
	
	/* GENERATING RIGHT CHILD */
	// Right NOW and Left after
	if ((current_sum + remaining_sum - W[k] >= target_sum) && (current_sum + W[k+1] <= target_sum)) {
		X[k] = 0;
		cout << "Calling RIGHT with " << k+1 << " = FALSE" << endl;
		sumofsub(W,X, current_sum, k+1, (remaining_sum-W[k]), target_sum);
	
	}
}

int main () {

	int W[4] = {1,4,3,2}; // Main Array
	int X[4] = {0,0,0,0}; // Mask Array
	int sum = 5;

	// Print the array
	cout << "\nInput Array: ";
	for (int i = 0; i < 4; i++) {
		cout << W[i] << ", ";
	}
	cout << "\n";
	
	sumofsub(W,X,0,0,10,5);

	

}
