#include <bits/stdc++.h>
using namespace std;
int comp = 0, mov = 0;

void insertionSort(int arr[], int n) {
int i, key, j;
for (i = 1; i < n; i++) {
	comp += 1;
	key = arr[i];
	j = i-1;
	bool indicator = false;

	while (j >= 0 && arr[j] > key) {
		comp += 2;
		arr[j+1] = arr[j];
		mov += 1;
		j = j-1;
		indicator = true;
	}
	
	comp += 2;
	

	arr[j+1] = key;
	
	if (indicator) mov += 1;
}
   comp += 1;
}


void printArray(int arr[], int n)
{
int i;
for (i=0; i < n; i++)
	printf("%d ", arr[i]);
printf("\n");
}



int main()
{
	
	clock_t begin = clock();
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << "Original Array -- "<< endl;
	printArray(arr, n);
	
	insertionSort(arr, n);
	clock_t end = clock();
	
	double elapsed_time = double(end - begin)/CLOCKS_PER_SEC;
	
	cout << "Sorted Array -- "<< endl;
	printArray(arr, n);
	
	cout << endl << "Size = " << n << ", comparisions = " << comp << ", movements = " << mov << ", elapsed_time = " << elapsed_time << endl;

	return 0;
}


