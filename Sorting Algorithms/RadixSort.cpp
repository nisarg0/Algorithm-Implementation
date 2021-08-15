#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int>& arr, int exp) {
    vector<int> freq(10,0);
    vector<int> ans(arr.size());

    for(int i=0;i<arr.size();i++)
        freq[(arr[i]/exp) %10]++;         // arr[i]/100 %10 gives ele at 1000th place
    
    vector<int> prefix_index(10,0);
    for(int i=0;i<10;i++){
        prefix_index[i] = freq[i];
        if(i != 0)
            prefix_index[i] += prefix_index[i-1];
    }

    // To convert this prefix arr to index arr
    // Each value in prefix[i] represnts max index of i  
    for(int i=0;i<freq.size();i++)
        prefix_index[i]--;                                                 

    // We traverse in reverse as we want to keep Radix sort stable 
    for(int i=arr.size()-1;i>=0;i--){
        int index = (arr[i]/exp)%10;
        ans[prefix_index[index]] = arr[i]; 
        prefix_index[index]--;
    }

    arr = ans;
}

// Works for +ve elements
void radixSort(vector<int> &arr){
    int i,max_val = INT_MIN;
    for(i=0;i<arr.size();i++)
        max_val = max(max_val,arr[i]);

    int exp = 1;
    // Loop till the msb of max_val
    while(exp <= max_val) {
        // apply count sort on (exp)'s place
        countSort(arr,exp);
        exp *= 10;
    }
}

void print(vector<int> arr){
    cout <<  "\nSorted Array is : ";
    for(int i=0;i<arr.size();i++)
        cout << arr[i] <<" ";
    cout << endl;
}

int main(){
    int n = 10;
    vector<int> arr = {4533,6534,5881,2896,104,7435,8236,7865,909,6450};

    radixSort(arr);
    print(arr);
}