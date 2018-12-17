	#include <bits/stdc++.h>
using namespace std;

/*

	Problem Description: 
	
	Given three integers N, M and X, the task is to find the number of ways to form an array, 
	such that all consecutive numbers of the array are distinct, and the value at any index 
	of the array from 2 to N – 1(Considering 1 based indexing) lies between 1 and M, 
	while the value at index 1 is X and the value at index N is 1.
	
	Note: Value of X lies between 1 and M.

*/
					
int NoOfWaysToFormDistinctArrays(int N, int m, int X) {
    
    int dp[N+1][2];
    
    if (X == 1) {
        dp[0][0] = 1;
        dp[0][1] = 0;
    } else {
        dp[0][0] = 0;
        dp[0][1] = m-1;
    }
    
    if (X == 1) {
        dp[1][0] = 0;
        dp[1][1] = m-1;
    } else {
        dp[1][0] = 1;
        dp[1][1] = m-2;
    }
    
    
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][0]*m-1 + dp[i-1][1]*m-2;
    }
    
    return dp[N-1][0];
    
}



int main() {
	
	int ways = NoOfWaysToFormDistinctArrays(2,3,2);
	cout << "ways = " << ways << endl;
	
	return 0;
}
