// Merge Sort O(nlog(n)) with O(n) space
// else O(nlog^2(n)) with O(1) space

#include<bits/stdc++.h>

using namespace std;
// Merges 2 arrays [lo,mid], [mid+1,hi]
void merge(vector<int> &arr,int lo, int hi, int mid){
    int i = lo,j = mid+1;
    vector<int> ans;

    while(i <= mid or j <= hi){
        int l = i > mid ? INT_MAX : arr[i];  // is not in range take INT_MAX
        int r = j > hi ? INT_MAX : arr[j];

        if(l<r)
            ans.push_back(l),i++;
        else
            ans.push_back(r),j++;
    }
    for(i=0;i<ans.size();i++)
        arr[lo+i] = ans[i];
}

// We merge sorted array so call Merge Sort first then merge
void mergeSort(vector<int> &arr, int lo, int hi) {
    if(lo>=hi)
        return;
    
    int mid = (lo+hi)/2;
    mergeSort(arr,lo,mid);
    mergeSort(arr,mid+1,hi);

    merge(arr,lo,hi,mid);
}

void print(vector<int> arr){
    cout <<  "Sorted Array is : ";
    for(int i=0;i<arr.size();i++)
        cout << arr[i] <<" ";
    cout << endl;
}

int main(){
    int n = 10,i;
    vector<int> arr = {3,6,1,2,10,7,8,5,9,0};

    mergeSort(arr,0,n-1);
    print(arr);
}