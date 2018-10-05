#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int brr[10]={1,2,3,4,5,6,7,8,9,10};
    int i,j,d,n,temp;
    cin >> d >> n;
    for(i=0;i<10;i++)
        cout<<arr[i]<<" ";

    for(j=0;j<d;j++)
    {
      temp=arr[0];
      for(i=0;i<n;i++)
       {
           if(i==(n-1))
               arr[n-1]=temp;
           else
               arr[i]=arr[i+1];
       }
    }

    // OUTPUT of the first iteration

    cout << endl;
    for(i=0;i<10;i++)
        cout<<arr[i]<<" ";

    node *head = new node;
    node *first = new node;
    first = head;
    for(i=0;i<n;i++)
    {
        if(i<d)
        {
            if(i==0)
            {
                head->data=brr[i];
                head->next=NULL;
            }
            else
            {
                node *trav = new node;
                trav->data = brr[i];
                trav->next = NULL;
                head->next = trav;
                head=trav;
            }
        }
        else        {
            brr[i-d]=brr[i];
        }
    }

    for(i=(n-d);i<n;i++)
    {
       brr[i]=first->data;
       first=head->next;
    }





        cout << endl;
    for(i=0;i<10;i++)
        cout<<brr[i]<<" ";
}
