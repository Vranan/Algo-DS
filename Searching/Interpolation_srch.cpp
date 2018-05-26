#include <iostream>
using namespace std;

int main() {
    
    int i=0,arr_len=15,srch_val = 0,found = 0,hi=0,lo=0,mid=0;
    int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23,
                  24, 33, 35, 42, 47};
    for(i=0;i<arr_len;i++)
    {
        cin >> arr[i];
    }
    cin >> srch_val;
    hi = arr_len;
    lo = 0;
    mid = (hi+lo)/2;
    while(hi >= lo)
    {
        if(arr[mid] == srch_val)
            {
                found = 1;
                cout << "Found the value at - " << mid << endl;
                break;
            }
        else if(srch_val > arr[mid])
            {
                lo = mid + 1;
                mid = lo + ((hi-lo)/(arr[hi]-arr[lo]))*(srch_val - arr[lo]);
            }
        else if(srch_val < arr[mid])
            {
                hi = mid - 1;
                mid = lo + ((hi-lo)/(arr[hi]-arr[lo]))*(srch_val - arr[lo]);
            }
                
    }
    if(found = 0)
        cout << "Value doesn't exist" << endl;
        
	return 0;
}
