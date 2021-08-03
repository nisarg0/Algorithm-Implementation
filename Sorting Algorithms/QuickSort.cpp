// O(nlog(n))  --> average time Complexcity 
// O(n^2)      --> worst case (If 1st element is chosen as pivot and arr is sorted)
// O(1)        --> Extra Space 

#include<bits/stdc++.h>
using namespace std;
// All ements to the left of pivot are less than pivot and to the right are greater
// It means the element is in its sorted position
int partition(vector<int> &arr, int lo, int hi){
    int j,i = lo+1;
    int pivot = arr[lo];  // We try to find index of pivot
/*
    arr[lo] is our pivot
    Our array lo to hi is divided into 3 regions:
    [lo+1,j-1]      -->     Less than Pivot
    [j,i-1]         -->     More than Pivot
    [i,hi]          -->     Unchecked
*/
    
    for(j=lo+1;j<=hi;j++){
        if(arr[j] < pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    // i-1 is largest index with no. less than pivot 
    // So it is pivot index
    swap(arr[lo],arr[i-1]);
    return i-1;
}

// Divide and Conquer Algo
void quickSort(vector<int> &arr, int lo, int hi){
    if(lo>=hi)
        return;
    int pivot_index = partition(arr,lo,hi);
    quickSort(arr,lo,pivot_index-1);
    quickSort(arr,pivot_index+1,hi);
}

void print(vector<int> arr){
    cout <<  "Sorted Array is : ";
    for(int i=0;i<arr.size();i++)
        cout << arr[i] <<" ";
    cout << endl;
}

int main(){
    int n = 10;
    vector<int> arr = {3,6,1,2,10,7,8,5,9,0};

    quickSort(arr,0,n-1);
    print(arr);
}