// Link --> https://leetcode.com/problems/continuous-subarray-sum/
Find if is there any subarray with sum in multiple of k

bool find(vector<int> arr, int k){
    set<int> s;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        int val = sum%k==0?k:sum%k;
        if(s.find(val) == s.end())
            s.insert(val);
        else
            return false;
    }
    return true;
}