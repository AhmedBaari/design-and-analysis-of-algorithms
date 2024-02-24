#include <iostream>
using namespace std;


void bruteForce(float A[]) {
	// Maximum sum be lowest possible
	float max_sum = -99999;
	int count = 0;
	
	int size = 11;
	int left = 999;
	int right = 999;
	
	// Iterate through A and find
	for (int i = 0 ; i < size ; i++) {

		float currentSum = 0;
		
		for (int j = i ; j <= size-1 ; j++) {
			count = count + 1;
			currentSum = currentSum + A[j];
			
			if (currentSum> max_sum) {
				max_sum = currentSum;
				 left = i;
				 right = j; // Stops wherever the sum is max
			}
		}	
	}
	cout << "\n\nLEFT: " << left << "\nRIGHT: " << right << "\nSUM: " << max_sum << endl;
}


int main () {
	cout << "Hello World" << endl;
	float A[11]= {8.2, -0.3,5.0, 9.9, -19.4, 1.4, 3.6, -9.3,-15.3, -17.4, 44.3};
	
	
	cout << "INITIAL ARRAY: ";
	for (int i = 0; i < sizeof(A)/sizeof(float); i++) {
		cout << A[i] << ", ";
	}
	cout << endl;
	
	bruteForce(A);
}
