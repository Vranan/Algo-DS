#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int n,arr_len, jmp_blk, loops,i=0,srch_val,comp_loops=0,diff_point=0;
    cin >> arr_len;
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
    for(i=0;i<arr_len;i++)
    {
        cin >> arr[i];
    }
   
	cin >> srch_val;
	
	while(arr[min(step,n)-1] < srch_val)
	{
	    prev = step;
		step = step + sqrt(n);
		if(prev >= n)
		     return -1;
	}
	
	while(arr[prev] < srch_val)
	{
	   prev++;
	   if(prev == min(step,n))
	      return -1;
	}
	
	if(arr[prev] == srch_val)
	    cout << "Found" << endl;

	return 0;
}