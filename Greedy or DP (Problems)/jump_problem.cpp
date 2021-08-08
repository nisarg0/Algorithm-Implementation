// Link : https://leetcode.com/problems/jump-game-ii/
// Reach from 0th index to nth index with minimum number of jumps
// arr[i] represents max jump possible from ith index.

#include<bits/stdc++.h>
using namespace std;

int min_jump(vector<int> arr)
{
    int n = arr.size(),i;
    int range_of_jump = arr[0]; // This is the index upto which we can reach
    int max_reachable_index = arr[0];   // Next maximum reachable index from current range (1 more jump will be neede)
    int jump = 1;

    // We have already made our 1st jump
    for(i=1;i<n-1;i++)
    {
        max_reachable_index = max(arr[i]+i,max_reachable_index);

        // we can't go anyfurther without doing an extra jump
        if(i == range_of_jump)
        {
            range_of_jump = max_reachable_index;
            jump++;
        }
    }
    return jump;
}

signed main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it:arr)
        cin >> it;
    
    cout << min_jump(arr) << "\n";    
}