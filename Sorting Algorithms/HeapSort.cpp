// Given an array implementation of Complete Binary Tree
// Heapify function takes O(logn) 
// n is the size of array.
#include<bits/stdc++.h>

using namespace std;

// Generates heap from ith node and it's children.
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(vector<int> &arr, int n)
{
    // Build heap (rearrange array) 
    // We did this from n/2-1 -> 0 b'coz for a complete binary tree last n/2 elements are leave nodes.
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Now arr is a max heap
    // Pass by ref

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
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
    vector<int> arr{10,3,2,5,7};

    heapSort(arr,n);

    print(arr);
}
