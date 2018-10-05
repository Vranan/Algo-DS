#include <bits/stdc++.h>
#include <string>
using namespace std;

int prec(char ch)
{
    switch(ch)
    {
        case '^' : return 5;
        case '/' : return 4;
        case '*' : return 4;
        case '+' : return 3;
        case '-' : return 3;
        default : return -1;
    }
}

void infix_to_postfix(string s)
{
   string ns;
   std::stack <char> st;
   st.push('N');
   int l = s.length();
   for(int i=0;i<l;i++)
   {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            ns += s[i];
        else if(s[i] == '(')
            st.push('(');
        else if(s[i] == ')')
            {
                while(st.top() != 'N' &&  st.top() != '(')
                   {
                       char c = st.top();
                       st.pop();
                       ns += c;
                   }
                if(st.top() == '(')
                   {
                       char c = st.top();
                       st.pop();
                   }
            }
        else
            {
                      while(s[i] != 'N' && prec(s[i]) <= prec(st.top()))
                        {
                          char c = st.top();
                          st.pop();
                          ns += c;
                        }
                     st.push(s[i]);
            }
   }
   while(st.top() != 'N')
      {
          char c = st.top();
          st.pop();
          ns += c;
      }
      
      cout << "infix to postfix conversion of " << endl << s << " = " << ns << endl;
}

int main() 
{
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    infix_to_postfix(s);
	return 0;
}