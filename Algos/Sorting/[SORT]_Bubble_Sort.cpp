#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int N)
{
    int i=0;
    for(i=0;i<N;i++)
    {
        cout << a[i] << " ";
    }
}

void BubbleSort(int a[],int N)
{
    int i=0,temp=0,k=N,j=0,min=0;
    
    for(i=0;i<N-1;i++)
    {
        k--;
        min = 0;
        for(j=0;j<k;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                min=1;
            }
        }
        if(min==0)
           break;
    }
	cout << "Final Array -- " << endl;
    printArray(a,N);
}




int main()
 {
	int T,N,i=0,a[1100];
	cin >> T;
	while(T--)
	{
	    cin >> N;
	    for(i=0;i<N;i++)
	    {
	       cin >> a[i];
	    }
	    BubbleSort(a,N);
	}
	return 0;
}