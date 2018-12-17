#include<bits/stdc++.h>
using namespace std;

//#include <stdio.h> 

/*
void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} */
int comp = 0, mov = 0;
void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	for (i = 0; i < n-1; i++) 
	{ 
		comp += 1;
		min_idx = i; 
		for (j = i+1; j < n; j++) {
			comp += 1;
			if (arr[j] < arr[min_idx]) {
 				min_idx = j; 
 			}
 		}
 		comp += 1;

		swap(arr[min_idx], arr[i]); 
		mov += 1;
	}
	comp += 1; 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int main() 
{ 
	clock_t begin = clock();
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	cout << "Original Array -- " << endl;
	printArray(arr, n);  
	
	selectionSort(arr, n); 
	clock_t end = clock();
	
	double elapsed_time = double(end - begin)/CLOCKS_PER_SEC;
	
	cout << "Sorted Array -- " << endl;
	printArray(arr, n);
	
	cout << endl << "Size = " << n << ", comparisions = " << comp << ", movements = " << mov << ", elapsed_time = " << elapsed_time << endl;
	return 0; 
} 



