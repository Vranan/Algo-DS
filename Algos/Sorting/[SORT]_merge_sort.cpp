#include<bits/stdc++.h>
using namespace std;

int comp = 0, mov = 0;

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i]; 
		mov += 1;
		comp += 1;
	}
	comp += 1;
	
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1+ j]; 
		mov += 1;
		comp += 1;
	}
	comp += 1;

	
	i = 0; 
	j = 0; 
	k = l; 
	
	while (i < n1 && j < n2) { 
	
		comp += 2;
		
		if (L[i] <= R[j]) { 
			mov += (arr[k] == L[i]) ? 0 : 1;
			arr[k] = L[i]; 
			i++;
			 
		} else { 
			mov += (arr[k] == R[j]) ? 0 : 1;
			arr[k] = R[j]; 
			j++; 
		} 
		
		comp += 1;
		k++; 
	}
	
	comp += 2; 
	
	while (i < n1) {
	 
	 	comp += 1;
	 	mov += (arr[k] == L[i] ? 0 : 1);
		arr[k] = L[i]; 
		i++; 
		k++; 
	}
	comp += 1; 

	
	while (j < n2) {
		comp += 1; 
		mov += (arr[k] == R[j] ? 0 : 1);
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
	comp += 1;
} 

void mergeSort(int arr[], int l, int r) { 
	
	if (l < r) { 
		
		int m = l+(r-l)/2; 

		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
	comp += 1;
} 


void printArray(int A[], int size) { 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 


int main() { 

	clock_t begin = clock();
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << "Original Array" << endl; 
	printArray(arr, n);
	
	mergeSort(arr, 0, n - 1); 
	clock_t end = clock();
	
	double elapsed_time = double(end - begin)/CLOCKS_PER_SEC;
	
	cout << "Sorted array -- " << endl; 
	printArray(arr, n); 
	
	cout << endl << "Size = " << n << ", comparisions = " << comp << ", movements = " << mov << ", elapsed_time = " << elapsed_time << endl;
	return 0; 
} 

