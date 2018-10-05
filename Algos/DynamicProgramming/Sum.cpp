/* 
Given coins with values 1, 3, and 5.
And the sum S is set to be 11.
Find minimum number of coins needed to obtain the sum 11. 
The coins can be repeated any number of times.
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void itr(vector<int> mv) {
    for (vector<int>::iterator it = mv.begin(); it != mv.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
}

int minc(int s, vector<int> vec) {
	vector<int> min;
	// since sum of 0 can be made with 0 coins.
	min.push_back(0);
	
	// the number of coins needed to get a sum of i below should be infinite.
	for (int i = 1; i <= s; i++) {
		min.push_back(numeric_limits<int>::max());
	}
	
	for (int i = 1; i <= s; i++) {
		for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
			if ((*it <= i) && (min[i-(*it)] < min[i]))
				min[i] = min[i-(*it)] + 1;
		}
	}
	return min[s];
}

int main() {
	clock_t c_strt = clock();
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	int minv = minc(11, vec);
	cout << "minimum value = " << minv << endl;
	clock_t c_end = clock();
	cout << "c_start = " << c_strt << ", c_end = " << c_end << ", c_diff = " << c_end - c_strt << endl;
	
}
