#include<bits/stdc++.h>
using namespace std;

int comp = 0, mov = 0;
int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) {
		comp += 1;
		if (arr[i] > mx) {
			mx = arr[i]; 
		}
		comp += 1;
	}
	comp += 1;
	return mx; 
} 

void countSort(int arr[], int n, int exp) 
{ 
	int output[n]; 
	int i, count[10] = {0}; 

	for (i = 0; i < n; i++) {
		comp += 1;
		count[ (arr[i]/exp)%10 ]++;
	}
	comp += 1;

	for (i = 1; i < 10; i++) {
		comp += 1;
		count[i] += count[i - 1]; 
	}
	comp += 1;
	
	for (i = n - 1; i >= 0; i--) {
		comp += 1; 
		mov += (output[count[ (arr[i]/exp)%10 ] - 1] == arr[i] ? 0 : 1);
		
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 
	comp += 1;
 
	for (i = 0; i < n; i++) {
		comp += 1;
		mov += (arr[i] == output[i]) ? 0 : 1;
		arr[i] = output[i]; 
	}
	comp += 1;
} 
 
void radixsort(int arr[], int n) {
  
	int m = getMax(arr, n); 

	for (int exp = 1; m/exp > 0; exp *= 10) {
		comp += 1;
		countSort(arr, n, exp); 
	}
	comp += 1;
} 

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl;
} 

int main() 
{ 
	clock_t begin = clock();
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	cout << "Original Array -- " << endl;
	printArray(arr, n); 

	radixsort(arr, n); 
	clock_t end = clock();
	double elapsed_time = double(end - begin)/CLOCKS_PER_SEC;
	
	cout << "Sorted Array -- " << endl; 
	printArray(arr, n); 
	
	cout << endl << "Size = " << n << ", comparisions = " << comp << ", movements = " << mov << ", elapsed_time = " << elapsed_time << endl;
	
	return 0; 
} 

