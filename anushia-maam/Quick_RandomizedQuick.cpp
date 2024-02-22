#include <iostream>
#include <fstream>
#include <limits.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
class Quick_RandomizedQuick_Sort{
	private:
		long int a[11000];
	public:
		void readInput(int n, int type){
			char s[16];
			switch (type){
				case 0: strcpy(s, "input.txt"); break;
				case 1: strcpy(s, "input-asc.txt"); break;
				case 2: strcpy(s, "input-desc.txt"); break;
				case 3: strcpy(s, "input-equal.txt"); break;
			}
			ifstream fin(s);
			for (int i=0; i<n; i++)
			   fin >> a[i];
			fin.close();
		}
		void writeOutput(int n){
			ofstream fout("output.txt");
			for (int i=0; i<n; i++)
			   {
			   fout << a[n-1-i] << "\t";
			   }
		       fout.close();   
		}
		int Partition(int p, int r, int &count)
		{
			int key,i,j,n,t;
			key=a[r];	
			i=p-1;
			for(j=p;j<=r-1;j++)
			{
				count++;
				if(a[j]<=key)
				{
					i++;
					swap(a[i],a[j]);
				}
			}
			count++;
			swap(a[i+1],a[j]);
			return i+1;
		} 

		
		int Randomized_Partition(int p, int r, int &count)
		{
			int key,i,j,n,t;
			int pivot_index=p + ( rand() % ( r - p + 1 ) );
		
			//cout<<"p="<<p<<" "<<"r="<<r<<"pivot"<<pivot_index<<endl;
			swap(a[r],a[pivot_index]);
			return Partition(p, r, count);
		}

		void quickSort(int p,int  r, int &count)
		{
			if(p<r){
				int q = Partition(p, r, count);
				quickSort(p, q-1, count);
				quickSort(q+1, r, count);
			}
		}
			void Randomized_quickSort(int p,int  r, int &count)
		{
			if(p<r){
				int q = Randomized_Partition(p, r, count);
				Randomized_quickSort(p, q-1, count);
				Randomized_quickSort(q+1, r, count);
			}
		}
		void display(int n)
		{
			for(int i=0;i<n;i++) 
				cout<<a[i]<<" ";
			cout<<endl;
		}

};
int main(){
	Quick_RandomizedQuick_Sort s;
	int ch;
	int len[7] = {10, 50, 100, 500, 1000, 5000, 10000};
	do {
		cout << "  1. Quick Sort, 2. Randomized Quick Sort" << endl;
		cout << "Enter your option: ";
		cin >> ch;
		if (ch != 1 && ch!=2) 
		    break;
		cout << "For Random Input: " << endl;
		for (int i=0; i<7; i++){
			int count = 0;
			int n = len[i];
			s.readInput(n, 0);
			switch (ch){
				
				case 1: 
				        s.quickSort(0, n-1, count);
				        break;
				case 2: 
					   if(n<=50)
					   {cout<<"before sorting\n";
					    s.display(n);
				       }
					   s.Randomized_quickSort(0, n-1, count);
					   if(n<=50)
					   {cout<<"after sorting\n";
					    s.display(n); 
					   }
				       break;
				
			}	
			s.writeOutput(n);
			cout << "Input size: " << n << "\t" << "No. of Comparisons: " << count << endl;
		}
		cout << endl << "For ascending order input: " << endl;
		for (int i=0; i<7; i++){
			int count = 0;
			int n = len[i];
			s.readInput(n, 1);
			switch (ch){
				
				case 1: 
				        s.quickSort(0, n-1, count);
				        break;
				case 2:
					    s.Randomized_quickSort(0, n-1, count);
					    break;
			}	
			s.writeOutput(n);
			cout << "Input size: " << n << "\t" << "No. of Comparisons: " << count << endl;
		}
		cout << endl << "For descending order input: " << endl;
		for (int i=0; i<7; i++){
			int count = 0;
			int n = len[i];
			s.readInput(n, 2);
			switch (ch){
				
				case 1: 
				        s.quickSort(0, n-1, count);
				        break;
				case 2: 
					   s.Randomized_quickSort(0, n-1, count);
				       break;
				
			}	
			s.writeOutput(n);
			cout << "Input size: " << n << "\t" << "No. of Comparisons: " << count << endl;
		}
		cout << endl << "For all elements are same input: " << endl;
		for (int i=0; i<7; i++){
			int count = 0;
			int n = len[i];
			s.readInput(n, 3);
			switch (ch){
				
				case 1: 
				        s.quickSort(0, n-1, count);
				        break;
				case 2: 
					   s.Randomized_quickSort(0, n-1, count);
				       break;
				
			}	
			s.writeOutput(n);
			cout << "Input size: " << n << "\t" << "No. of Comparisons: " << count << endl;
		}
	}
	while (ch < 5);
	return 0;
}
