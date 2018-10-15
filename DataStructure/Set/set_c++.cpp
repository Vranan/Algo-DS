#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q, q1, q2;
    set<int> myset;
    cin >> Q;
	set<int>::iterator it;
    while (Q--) {
    	cin >> q1 >> q2;
    	if (q1 == 1)
    		myset.insert(q2);
    	else if (q1 == 2) {
    		it = myset.find(q2);
    		myset.erase(it);
    	}
    	else if ((q1 == 3) && *(myset.find(q2)) == q2)
    		cout << "Yes" << endl;
    	else 
    		cout << "No" << endl; 
    	
    		
	}
    return 0;
    
}
