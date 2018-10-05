#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n,arr_len, jmp_blk, loops,i=0,srch_val,comp_loops=0,diff_point=0;
    cin >> arr_len;
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
    for(i=0;i<arr_len;i++)
    {
        cin >> arr[i];
    }
    //
	//arr_len = sizeof(arr)/sizeof(arr[0]);
	jmp_blk = sqrt(arr_len);
	comp_loops = arr_len/jmp_blk;
	diff_point = comp_loops*jmp_blk;
	cin >> srch_val;
	int found=0,loop=0,j=0;
	i=0;
	i = i+jmp_blk;
	//cout << "arr_len = " << arr_len << ", jmp_blk = " << jmp_blk << ", i = " << i << endl;
	//cout << "srch_val = " << srch_val << endl; 
	
	while(i<=arr_len)
	{
	    cout << "i = " << i << ", arr[" << i-1 << "] = " << arr[i-1] << endl;
	    if(srch_val == arr[i-1])
	    {   
	        found = 1;
	        cout << "1. Value exists at - " << i-1 << endl;
	        break;
	    }
	    else if(srch_val > arr[i-1])
	    {
	         i = i + jmp_blk;
	         if(i==diff_point)
	            {
	                while(i<arr_len)
	                {
	                    if(srch_val == arr[i])
	                       {
	                           found = 1;
	                           i = arr_len + 1;
	                           break;
	                       }
	                    i++;
	                }
	                if (found == 0)
	                    break;
	            }
	    }
	    else if(srch_val < arr[i-1])
	    {
	        j = i-jmp_blk;
	        cout << "------- j = " << j << ", i = " << i << endl;
	        while(j<i)
	        {
	            if(srch_val == arr[j])
	                {
	                    found = 1;
	                    cout << "2. Value exists at - " << j << endl;
	                    break;
	                }
	             j++;
	        }
	        if (found == 1)
	           break;
	    }
	}
	
	cout << "xxxxxxxxxxx Value of i = " << i << ", Found = " << found << endl;
	
   if(found == 0)
     cout << "Value doesn't exist " << endl;
    else
      cout << "3. Value exists" << endl;

	return 0;
}
