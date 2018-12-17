#include<bits/stdc++.h>
using namespace std;

public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int start = 0;
        int minlen = INT_MAX;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                minlen = min(minlen, i-start+1);
                sum -= nums[start++];
            }
        }
        
        return minlen == INT_MAX ? 0 : minlen;
        
    }

int main() {

	return 0;
}

