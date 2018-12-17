#include<bits/stdc++.h>
using namespace std;

int comp = 0;
int mov = 0;

void heapify(int arr[], int n, int i) {
	
	int root = i;
	int left_child = 2*i + 1;
	int right_child = 2*i + 2;
	
	if (left_child < n && arr[left_child] > arr[root]) {
		root = left_child;
	}
	comp += 2;
	
	if (right_child < n && arr[right_child] > arr[root]) {
		root = right_child;
	}
	comp += 2;
	
	
	if (root != i) {
		swap(arr[i], arr[root]);
		mov += 1;
		heapify(arr, n, root);
	}
	comp += 1;
	
}

void sort(int arr[], int n) {
	
	
	for (int i = ((n/2)-1) ; i >= 0; i--) {
		comp += 1;
		heapify(arr, n, i);
	}
	comp += 1;
	
	for (int i = n-1; i >= 0; i--) {
		comp += 1;
		swap(arr[0], arr[i]);
		mov += 1;
		heapify(arr, i, 0);
	}
	comp += 1;
	
}

void printArray(int arr[], int sz) {
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	clock_t begin = clock();
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(*arr);
	
	cout <<"Original Array -- " << endl; 
	printArray(arr, n);
	
	cout << endl;
	sort(arr, n);
	clock_t end = clock();
	double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
	
	cout << "Sorted Array -- " << endl;
	printArray(arr, n);
	
	cout << endl << "Size = " << n << ", comparisions = " << comp << ", movements = " << mov << ", elapsed_time = " << elapsed_time << endl;
	return 0;
}

