// Given array of size n has elements from 0 to n-1.
// Sorting can be done in O(n) using cycleSort
#include<bits/stdc++.h>

using namespace std;

void cycleSort(vector<int>& arr, int n) {
    int i = 0;

    while(i<n) {
        if(arr[i] != arr[arr[i]]) 
            swap(arr[i], arr[arr[i]]);
        else
            i++; // Move to next ele after the element in ith index is i
    }
}

void print(vector<int> arr){
    cout <<  "Sorted Array is : ";
    for(int i=0;i<arr.size();i++)
        cout << arr[i] <<" ";
    cout << endl;
}

int main(){
    int n = 5;
    vector<int> arr{2,3,4,1,0};

    cycleSort(arr,n);

    print(arr);
}