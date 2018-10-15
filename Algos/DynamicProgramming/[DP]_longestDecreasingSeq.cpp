/*

Given a sequence of N numbers – A[1] , A[2] , …, A[N] . Find the length of the longest non-decreasing sequence.

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ldec(vector<int> vec) {
	vector<int> S;
	int sz = vec.size();
	int max = 1;
	
	for (int i = 1; i <= sz; i++) {
		S.push_back(1);
	}
	int i = 1;
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); it++) {
		if (*(it+1) >= *(it))
			S[i+1] = S[i] + 1;
		
		if (S[i+1] > max)
			max = S[i+1];
		
		i++;
	}
	cout << "max = " << max << endl;
}

int main() {

	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(6);
	vec.push_back(7);
	ldec(vec);

}