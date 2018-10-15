#include <bits/stdc++.h>
using namespace std;

vector<int> bubble_sort(vector<int> vect,int size)
{
    int i=0,j=0,temp=0;
    for(i=0;i<size;i++)
    {
        for(vector<int>::iterator it=vect.begin();it<vect.end();it++)
        {
            if(*it<*(it+1))
            {
                temp=*it;
                *it = *(it+1);
                *(it+1) = temp;
            }
        }
    }
    return vect;
}

int main()
{
    int num=0,diff=0;
    cin >> num;
    vector<int> vec(num);
    for(vector<int>::iterator it = vec.begin();it <= vec.end();it++)
       cin >> *it;
    vec=bubble_sort(vec,(vec.end()-vec.begin()));
    for(vector<int>::iterator it = vec.begin();it < vec.end();it++)
       cout << *it << " ";
       
    return 0;
}
