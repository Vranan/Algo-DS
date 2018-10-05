#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int post_eval(string str)
{
    int l = str.length();
    int val =0;
    char c;
    std::stack<char> st;
    for(int i=0;i<l;i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
           {
              st.push(str[i]);
           }
        else
           {
             int n1 = int(st.top()) - 48;
             st.pop();
             int n2 = int(st.top()) - 48;
             st.pop();
             
             switch(str[i])
             {
                case '+': val = n1+n2+48;st.push(val);break;
                case '-': val = (n1-n2)+48;st.push(val);break;
                case '*': val = (n1*n2)+48;st.push(val);break;
                case '/': val = (n1/n2);val=val+48;st.push(val);break;
             }
           }
    }
val = st.top()-48;
return (val);
}

int main() 
{
    string s = "231*+9-";
    cout << "val after the evaluation = " << post_eval(s) << endl;
	return 0;
}