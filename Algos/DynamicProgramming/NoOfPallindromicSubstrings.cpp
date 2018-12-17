#include<bits/stdc++.h>
using namespace std;

    int countSubstrings(string s) {
       
        int res = 0;
        
        bool** dp = new bool*[s.length()];
        for (int i = 0; i < s.length(); i++) {
            dp[i] = new bool[s.length()];
        }
        //cout << "s.length()  = " << s.length() << endl;
        for (int i = s.length()-1; i >= 0; i--) {
            //cout << "i = " << i << endl;
            for (int j = i; j < s.length(); j++) {
                //cout << "1.  j = " << j << ", dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                //if (i < s.length()-1 && j > 0) {
                    dp[i][j] = (s[i] == s[j] && ((j-i < 3) || dp[i+1][j-1]));
                //} else {
                  //  dp[i][j] = (s[i] == s[j] && (j-i < 3));
                //}
                //cout << "2. dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                if (dp[i][j]) { 
                    res++;
                }
            }
                
        }
        
      /*  for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */
        
        return res;
        
    }


int main() {

	return 0;
}

