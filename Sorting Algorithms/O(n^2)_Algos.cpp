#include<bits/stdc++.h>
using namespace std;

// Insertion Sort
// We divide an array into 2 parts one is sorted and other is original array
// Size of first part keeps on increasing by 1 in each iteration and min value is put there
void insertionSort(vector<int> &arr){
    int n=arr.size(),i,j;
    for(i=0;i<n;i++){
        int min_val = arr[i];
        int min_val_indx = i;
        for(j=i+1;j<n;j++){
            if(arr[j] < min_val){
                min_val = arr[j];
                min_val_indx = j;
            }
        }
        swap(arr[i],arr[min_val_indx]);
    }
}

// Selection Sort
// Select 2 indices i,j where i<j.
// If arr[i] > arr[j] swap them.
void selectionSort(vector<int> &arr){
    int n=arr.size(),i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(arr[i]> arr[j])
                swap(arr[i],arr[j]);
}

// Bubble Sort
// Like a bubble move largest element to top
// keep on swapping adjacent elements
void bubbleSort(vector<int> &arr){
    int n = arr.size(),i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
}

// Stops the comparison when the array is sorted
void modified_bubbleSort(vector<int> &arr){
    int i,j,n=arr.size();
    bool isSorted = false;
    for(i=0;i<n and !isSorted;i++){
        isSorted = true;
        for(j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                isSorted = false;
                swap(arr[j],arr[j+1]);
            }
        }
    }
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

    // bubbleSort(arr);
    // modified_bubbleSort(arr);
    insertionSort(arr);
    // selectionSort(arr);
    print(arr);
}