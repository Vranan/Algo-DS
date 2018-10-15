#include <bits/stdc++.h>
using namespace std;

void printArray(int array[],int size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void rotate(int ar[],int begin, int end)
{
  int i=0,last_el=ar[end];
  
  for(i=end;i>begin;i--)
  {
     ar[i]=ar[i-1];
  }
  ar[i]=last_el;
}

void sort(int ar[],int sz)
{
    int i=0,j=0,pos=0;
    for(i=1;i<sz;i++)
    {
        pos=i;
        for(j=i-1;j>=0;j--)
        {
            if(ar[i]<ar[j])
                pos=j;
        }
        if(pos==i)
            continue;
        else
         rotate(ar,pos,i);   
    }
}

int main() {

    int size=0,i=0;
    int arr[1000];
    cin >> size;
    for(i=0;i<size;i++)
        cin >> arr[i];
    
    cout << "Before sorting Array --- " << endl;
    printArray(arr,size);
    sort(arr,size);
    cout << endl << "After sorting Array ---- " << endl;
    printArray(arr,size);
    
	return 0;
}
