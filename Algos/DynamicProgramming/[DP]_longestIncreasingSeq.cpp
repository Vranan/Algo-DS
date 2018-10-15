/* 
The Longest Increasing Subsequence problem is to find the longest increasing subsequence of a given sequence. 
Given a sequence S = {a1 , a2 , a3, a4, ............., an-1, an }, 
we have to find a longest subset such that for all j and i,  j<i in the subset aj<ai. 
*/
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

void itr(vector<int> mv) {
    for (vector<int>::iterator it = mv.begin(); it != mv.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
}

int longSeq(vector<int> seq) {
	int max = 0;
	vector<int> ls;
	for (int i = 0; i <= seq.size(); i++) {
		ls.push_back(1);
	}
	ls[1] = 1;
	int i = 1;
	for (vector<int>::iterator it = seq.begin(); it < seq.end(); it++) {
		if (*(it+1) > *it)
			ls[i+1] = ls[i]+1;
		
		if (max < ls[i+1])
			max = ls[i+1];
			
		i++;
	}
	cout << endl;
	itr(ls);
	return max;
}


int main() {
    clock_t tstart = clock();
	vector<int> seq;
	seq.push_back(1);
	seq.push_back(2);
	seq.push_back(4);
	seq.push_back(3);
	seq.push_back(5);
	seq.push_back(6);
	seq.push_back(7);
	seq.push_back(8);
	cout << "longest seq = " << longSeq(seq) << endl;
	clock_t tend = clock();
	cout << "clock periods for execution = " << tend - tstart << endl;
	return 0;
}