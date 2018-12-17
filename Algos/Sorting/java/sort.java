package algoAnalysis;

import java.util.Arrays;
import java.util.ArrayList;

public class sort {
	
	private int comp = 0;
	private int mov = 0;
	
	public sort() {
		comp = 0;
		mov = 0;
	}
	
	public void set (int c, int m) {
		comp = c;
		mov = m;
	}
	
	public int[] get () {
		int[] a = new int[2];
		a[0] = comp;
		a[1] = mov;
		return a;
	}
	
	//  ----------------------------------- Heap Sort --------------------------------
	
	public void heapSort(int arr[])
    {
        int n = arr.length;
 
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
			comp += 1;
			heapify(arr, n, i);
		}
		comp += 1;
 
        // One by one extract an element from heap
        for (int i=n-1; i>=0; i--) {
            // Move current root to end
			comp += 1;
			
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
			mov += 1;
 
            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
		comp += 1;
    }
 
    // To heapify a subtree rooted with node i which is
    // an index in arr[]. n is size of heap
    private static void heapify(int arr[], int n, int i)
    {
        int largest = i;  // Initialize largest as root
        int l = 2*i + 1;  // left = 2*i + 1
        int r = 2*i + 2;  // right = 2*i + 2
 
        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;
		comp += 2;
 
        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;
		comp += 2;
		
        // If largest is not root
        if (largest != i) {
			
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
			
			mov += 1;
 
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
		comp += 1;
    }
	
	
	//  ----------------------------------- Radix Sort --------------------------------
	
	private static int getMax(int arr[], int n){
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
 
    // A function to do counting sort of arr[] according to
    // the digit represented by exp.
    private static void countSort(int arr[], int n, int exp)
    {
        int output[] = new int[n]; // output array
        int i;
        int count[] = new int[10];
        Arrays.fill(count,0);
 
        // Store count of occurrences in count[]
        for (i = 0; i < n; i++) {
			comp += 1;
            count[ (arr[i]/exp)%10 ]++;
		}
		comp += 1;
 
        // Change count[i] so that count[i] now contains
        // actual position of this digit in output[]
        for (i = 1; i < 10; i++) {
			comp += 1;
            count[i] += count[i - 1];
		}
		comp += 1;
			 
        // Build the output array
        for (i = n - 1; i >= 0; i--) {
			comp += 1;
			
			mov += (output[count[ (arr[i]/exp)%10 ] - 1] == arr[i] ? 0 : 1);
            output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
			
            count[ (arr[i]/exp)%10 ]--;
        }
		comp += 1;
 
        // Copy the output array to arr[], so that arr[] now
        // contains sorted numbers according to curent digit
        for (i = 0; i < n; i++) {
			comp += 1;
			mov += (arr[i] == output[i]) ? 0 : 1;
            arr[i] = output[i];
			
		}
		comp += 1;
    }
 
    // The main function to that sorts arr[] of size n using
    // Radix Sort
    public static void radixSort(int arr[], int n)
    {
        // Find the maximum number to know number of digits
        int m = getMax(arr, n);
 
        // Do counting sort for every digit. Note that instead
        // of passing digit number, exp is passed. exp is 10^i
        // where i is current digit number
        for (int exp = 1; m/exp > 0; exp *= 10) {
			comp += 1;
			countSort(arr, n, exp);
		}
		comp += 1;
    }
	
	
	//  ----------------------------------- Merge Sort --------------------------------
	
	public void merge(int arr[], int l, int m, int r) 
	{ 
		// Find sizes of two subarrays to be merged 
		int n1 = m - l + 1; 
		int n2 = r - m; 

		/* Create temp arrays */
		int L[] = new int [n1]; 
		int R[] = new int [n2]; 

		/*Copy data to temp arrays*/
		for (int i=0; i<n1; ++i) {
			comp += 1;
			L[i] = arr[l + i]; 
			mov += 1;
		}
		comp += 1;
		
		for (int j=0; j<n2; ++j) {
			comp += 1;
			R[j] = arr[m + 1+ j];
			mov += 1;
		}			
		comp += 1;


		/* Merge the temp arrays */

		// Initial indexes of first and second subarrays 
		int i = 0, j = 0; 

		// Initial index of merged subarry array 
		int k = l; 
		while (i < n1 && j < n2) { 
			comp += 2;
			if (L[i] <= R[j]) { 
				mov += (arr[k] == L[i]) ? 0 : 1;
				arr[k] = L[i]; 
				i++; 
			} else { 
				mov += (arr[k] == R[j]) ? 0 : 1;
				arr[k] = R[j]; 
				mov += 1;
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

		while (j < n2) 
		{ 
			comp += 1;
			mov += (arr[k] == R[j] ? 0 : 1);
			arr[k] = R[j]; 
			j++; 
			k++; 
		} 
		comp += 1;
	} 

	public void mergeSort(int arr[], int l, int r) 
	{ 
		if (l < r) 
		{ 
			int m = (l+r)/2; 

			mergeSort(arr, l, m); 
			mergeSort(arr , m+1, r); 
 
			merge(arr, l, m, r); 
		} 
		comp += 1;
	} 
	
	//  ----------------------------------- Quick Sort --------------------------------
	
	public int partition(int arr[], int low, int high) 
	{ 
		int pivot = arr[high]; 
		int i = (low-1); // index of smaller element 
		for (int j=low; j<high; j++) 
		{ 
			comp += 1; 
			// If current element is smaller than or 
			// equal to pivot 
			if (arr[j] <= pivot) { 
				i++; 

				// swap(arr[i], arr[j]);
				
				int temp = arr[i]; 
				arr[i] = arr[j]; 
				arr[j] = temp; 
				
				mov += 1;
			} 
			comp += 1;
		}
		comp += 1;		

		int temp = arr[i+1]; 
		arr[i+1] = arr[high]; 
		arr[high] = temp; 
		// swap (arr[i+1], arr[high]);
		
		mov += 1;

		return i+1; 
	} 

	public void quickSort(int arr[], int low, int high) 
	{ 
		if (low < high) {
			
			/* pi is partitioning index, arr[pi] is 
			now at right place */
			int pi = partition(arr, low, high); 

			// Recursively sort elements before 
			// partition and after partition 
			quickSort(arr, low, pi-1); 
			quickSort(arr, pi+1, high); 
		} 
		comp += 1;
	} 
	
	
	// --------------------------------------- Selection Sort ---------------------------------
	
	public void selectionSort(int arr[]) 
	{ 
		int n = arr.length; 

		// One by one move boundary of unsorted subarray 
		for (int i = 0; i < n-1; i++) 
		{ 
			// Find the minimum element in unsorted array 
			int min_idx = i; 
			for (int j = i+1; j < n; j++) 
				if (arr[j] < arr[min_idx]) 
					min_idx = j; 

			// Swap the found minimum element with the first 
			// element 
			int temp = arr[min_idx]; 
			arr[min_idx] = arr[i]; 
			arr[i] = temp; 
		} 
	} 
	
	
	// ---------------------------------------- Insertion Sort --------------------------------------
	
	public void insertionSort(int arr[]) 
	{ 
		int n = arr.length; 
		for (int i=1; i<n; ++i) {
			comp += 1;
			int key = arr[i]; 
			int j = i-1; 
			Boolean indicator = false;

			while (j>=0 && arr[j] > key) { 
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

	 
	 
}
