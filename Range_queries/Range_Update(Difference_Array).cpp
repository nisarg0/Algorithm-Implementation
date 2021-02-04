// Reference link -> https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
// Range update in time complexity O(1) and space complexity O(n)
// Prefixsum and sufix sum is also a important technique but can be helpful only if 
// the operation in range is invertible(Ex add,sub or mul,div) can't be used for min,max or exor,and
#include<bits/stdc++.h>

using namespace std;
const int LIM = 1e3;
vector<int> difference(LIM,0);

void init(int arr[],int n)
{
    // 0th indx is init with value of 0th element in arr
    difference[0] = arr[0];
    // after that nothinng should be added (precaution)
    difference[n] = 0;
    for(int i=1;i<n;i++)
        difference[i] = arr[i]-arr[i-1];
}
// add x to all elements in between l and r (inclusive) in O(1)
void update_range(int arr[], int l, int r, int n, int x)
{
    // invalid ip
    if(l<0 or r >n-1 or l>r)    return;
    // we add x to lth indx so indirectly we add x to everthing after it
    difference[l] += x;
    // we need to subtract x from all the elements after r
    difference[r+1] -= x;
}

void print(int arr[], int n)
{
    arr[0] = difference[0];

    for(int i=1;i<n;i++)
        arr[i] = arr[i-1] + difference[i];

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[15] = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
    int n = sizeof(arr)/sizeof(int);
    int l=7,r=12;
    // Add 5 to all elements in range l to r
    update_range(arr,l,r,n,5);
    print(arr,n);
}