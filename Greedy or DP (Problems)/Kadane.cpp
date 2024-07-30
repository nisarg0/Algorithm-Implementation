// Find max_sum of sub array
// Question? Why should curr_sum start with arr[i] and not with something before ith index? 
// Assume started from start => Case 1: (some -ve sum) + arr[j] - we will already started from arr[j].
                             => Case 2: (Some +ve sum) + arr[j] - It's already part of curr_sum.
int kadane(vector<int> arr) {
    int n = arr.size(),i,ans_sum=0,curr_sum = arr[0];
    for(i=1;i<n;i++){
        curr_sum = max(arr[i],curr_sum+arr[i]);
        ans_sum = max(ans_sum,curr_sum);
    }
    return ans_sum;
}

// Find maximum product of subarray
// https://leetcode.com/problems/maximum-product-subarray/
int maxProductSubarray(vector<int> arr) {
    int ans = arr[0],max_val=arr[0],min_val=arr[0];
    for(int i=1;i<arr.size();i++) {
        if(arr[i] < 0)
            swap(max_val,min_val);
        
        max_val = max(arr[i],max_val*arr[i]);
        min_val = min(arr[i],min_val*arr[i]);
        
        ans = max(ans,max_val);
    }
    return ans;
}

// In such formula based question try to break down the formula
// Find max value of arr[i]+arr[j]+i-j where i<j
// https://leetcode.com/problems/best-sightseeing-pair/
int max_pair(vector<int> arr) {
    int i,n=arr.size(),prev_max = 0,ans=0;
    // TRICK - arr[i]+i  + arr[j]-j is to be maximized
    for(i=0;i<n;i++){
        ans = max(ans,prev_max+arr[i]-i);
        prev_max = max(prev_max,arr[i]+i);
    }
    return ans;
}

