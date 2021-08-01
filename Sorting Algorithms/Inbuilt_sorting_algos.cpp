#include<bits/stdc++.h>

using namespace std;

// Keep variables static to avoid some error
bool compare(int a, int b){
    return a<b; // Just write down the condn you want to satisfy
}

int main(){
    int n = 5;
    int arr[n] = {10,3,2,5,7};

    // Uses Intro sort
    // n < 16               -->  Insertion Sort
    // 16 < n < 2log(n)     -->  Quick Sort
    // 2log(n) < n          -->  Merge Sort
    sort(arr,arr+n);

    // Decreasing sort
    sort(arr,arr+n,greater<>());
    // Alternate and better
    // sort(arr+n,arr);

    // Sort using comparator 
    sort(arr,arr+n,compare);

    // Stable sorting using merge sort
    // O(n*log^2(n)) if memory is not availabe else O(nlog(n))
    stable_sort(arr,arr+n);

    for(int i=0;i<n;i++)    
        cout << arr[i] << " ";
}