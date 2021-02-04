// Question link -> https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650
// Artical link -> https://www.topcoder.com/community/competitive-programming/tutorials/binary-search

#include<bits/stdc++.h>

using namespace std;

int getMostWork(int folders[], int workers,int n) {
    // Number of workers maximum in a division can be between 1 and 10^6(Can be lower but in general)
    int lo = 1, hi = 1e5+1;

    while (lo < hi) 
    {
        int mid = lo + (hi - lo) / 2;
        int required = 1, sum = 0;

        for (int i = 0; i < n; ++i) 
        {
            if (sum + folders[i] <= mid) // the current worker can handle it
                sum += folders[i];
            else // assign nemidt worker
            {
                ++required;
                sum = folders[i];
            }
        }
        //               |            is the indx we want to find
        // F F F F F F F T T T T T T 
        // if(p(mid)==true) hi = mid
        if (required <= workers)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo; // lo=hi so doesn't matter
}

int main()
{
    int arr[15] = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
    int n = sizeof(arr)/sizeof(int);

    // Divide the work in 4 workers such that the work done per person is minimum
    cout << "Minimum possible maximum folders per person " <<getMostWork(arr,4,n);
}