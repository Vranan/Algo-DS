#include<bits/stdc++.h>
using namespace std;

int comp = 0, mov = 0;

void printArray(int arr[], int n) {
	int i;
	for (i=0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int partition(int arr[], int low, int high) {
	
	int i = (low - 1);
	int pivot = arr[high];
	
	for (int j = low; j < high; j++) {
		comp += 1;
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
			mov += 1;
		}
		comp += 1;
	}
	comp += 1;
	swap(arr[i+1], arr[high]);
	mov += 1;
	return (i+1);
}

void quicksort(int arr[], int low, int high) {
	
	if (high > low) {
		int pivot_pos = partition(arr, low, high);
		quicksort(arr, low, pivot_pos-1);
		quicksort(arr, pivot_pos+1, high);
	}
	comp += 1;
}


int main() {
	
	clock_t begin = clock();
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << "Original Array -- " << endl;
	printArray(arr, n); 
	
	quicksort(arr, 0, n-1);
	clock_t end = clock();
	
	double elapsed_time = double(end - begin)/CLOCKS_PER_SEC;
	
	cout << "Sorted Array -- " << endl;
	printArray(arr, n);
	
	cout << endl << "Size = " << n << ", comparisions = " << comp << ", movements = " << mov << ", elapsed_time = " << elapsed_time << endl;

	return 0;
}

