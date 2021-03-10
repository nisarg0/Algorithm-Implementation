// Question link -> https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650
// Artical link -> https://www.topcoder.com/community/competitive-programming/tutorials/binary-search
// Ref link -> https://www.youtube.com/watch?v=GU7DpgHINWQ

// Here in binary search we basically want o function that return boolean value if it is ans yes or no
// And we want the indxe from where true begins or false begins
#include<bits/stdc++.h>

using namespace std;

int getMostWork_method1(int folders[], int workers,int n) 
{
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

bool ispossible(int folders[],int n, int no, int workers)
{
    int required = 1, sum = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (sum + folders[i] <= no) // the current worker can handle it
            sum += folders[i];
        else // assign nemidt worker
        {
            ++required;
            sum = folders[i];
        }
    }
    if(required <= workers)
        return true;
    return false;
}

int getMostWork_method2(int folders[],int workers, int n)
{
    int hi=1e9,lo=0,mid;
    bool check_low,check_mid,check_upp;

    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        check_low=ispossible(folders,n,mid-1,workers);
        check_mid=ispossible(folders,n,mid,workers);
        check_upp=ispossible(folders,n,mid+1,workers);

        if(check_low==0 && check_mid==1)
                return mid;
        else if(check_mid==0 && check_upp==1)
                return mid+1;
        else if(check_upp==1)
                hi=mid+1;
        else if(check_low==0)
                lo=mid-1;
    }
    return 0;
}

int main()
{
    int arr[15] = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
    int n = sizeof(arr)/sizeof(int);

    // Divide the work in 4 workers such that the work done per worker is minimum
    cout << "Minimum possible maximum folders per person " <<getMostWork_method1(arr,4,n) << "\n";
    cout << "Minimum possible maximum folders per person " <<getMostWork_method2(arr,4,n);
}