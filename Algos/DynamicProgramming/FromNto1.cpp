/* 
On a positive integer, you can perform any one of the following 3 steps. 
1.) Subtract 1 from it. ( n = n - 1 ), 
2.) If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2  ), 
3.) If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3  ). 
Now the question is, given a positive integer n, find the minimum number of steps that takes n to 1. 
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <time.h>

using namespace std;

void itr(vector<int> mv) {
	int i = 0;
    for (vector<int>::iterator it = mv.begin(); it != mv.end(); it++) {
        cout << i << " -- " << *it << endl;
    }
    cout << endl;
}


int minSteps(int n) {
	vector<int> minc;
	minc.push_back(0);
	for (int i = 1; i <= n; i++) {
		minc.push_back(numeric_limits<int>::max());
	}
	
	minc[n] = 0;
	while (n >= 1) {
		// cout << n << " ";
		
		if (n % 2 == 0 && n/2 > 0)
			minc[n/2] = min(minc[n/2], (minc[n] + 1));
		else if (n % 3 == 0 && n/3 > 0) 
			minc[n/3] = min(minc[n/3], (minc[n] + 1));
		
			minc[n-1] = min(minc[n-1], (minc[n] + 1));
			
		n--;
	}
	// cout << endl;
	// itr(minc);
	return minc[1];
}

int main() {
	clock_t tstart = clock();
	cout << "min steps to 1 = " << minSteps(10) << endl;
	clock_t tend = clock();
	cout << "time of execution = " << tend - tstart << " clock cycles " << endl;
	return 0;
}