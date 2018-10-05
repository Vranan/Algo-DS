#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void itr(vector<int> mv) {
    for (vector<int>::iterator it = mv.begin(); it != mv.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
}

int minc(int s, vector<int> vec) {
	vector<int> minr;
	minr.push_back(0);
	
	for (int i = 1; i <= s; i++) {
		minr.push_back(numeric_limits<int>::max());
	}
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		int i = 0;
		while ((i+(*it)) <= s) {
			minr[i+(*it)] = min(minr[i+(*it)], (minr[i] + 1));
			i++;
		}
	}
	cout << "values in minr" << endl;
	itr(minr);
	return (minr[s]);
}


int main() {
	clock_t c_start = clock();
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	int minv = minc(11, vec);
	cout << "minimum value = " << minv << endl;
	clock_t c_end = clock();
	cout << "c_start = " << c_start << ", c_end = " << c_end << ", c_diff = " << c_end - c_start << endl;
}