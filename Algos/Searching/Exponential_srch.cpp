n#include <iostream>
#include <cmath>
using namespace std;
    
    int binary_search(int arr[],int,int,int x);
    
    int expo_srch(int arr[],int n,int x)
    {
        int return_val;
        if(arr[0]==x)
            return 0;
        
        int i=1;
        while(i<n && arr[i] <= x)
           {
               i=i*2;
           }
        return_val = binary_search(arr,i/2,min(i,n),x);  
        if(return_val > 0)
            return return_val;
           
    }
    
    int binary_search(int arr[],int l,int r,int x)
    { 
        int mid,return_val=-1;
        while(l<=r)
        {
           mid = (l+r)/2;
        
           if(arr[mid]==x)
            {
                return_val = mid;
                break;
            }
           else if(arr[mid] > x)    
               r = mid-1;
           else if(arr[mid] < x)
               l = mid+1;
        }
        return return_val;
    }
    
    int main()
    {
        int srch_val,index=-1;
       int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
       cin >> srch_val;
       index = expo_srch(arr,15,srch_val);
       if(index>0)
          cout << "Value exists at " << index << endl;
       else      
          cout << "Value doesn't exist" << endl;
          
	   return 0;
    }

