// Reference --> https://www.youtube.com/watch?v=U66U1-umNbQ&t=1s
// Reference --> https://www.youtube.com/watch?v=V343UXw4P3Y

// upper bound return first element which is >value. If not, return end().
// lower bound return first element which is ≥value. If not, return end().

/*
Elements are : 1 3 5 7 9 
******* lower_bound *********
lower bound of 5 in the set is: 5
lower bound of 1 in the set is: 1
lower bound of 4 in the set is: 5
****** upper_bound ************
upper bound of 5 in the set is: 7
upper bound of 1 in the set is: 3
upper bound of 4 in the set is: 5
*/

#include<bits/stdc++.h> 
using namespace std;

/*
* Intresting observation note worthy : 
* lo+(hi-lo)/2 = (lo+hi)/2  is skewed to towards lo. (ex. (1+4)/2 = 2.5 but it return 2)
* hi = mid can be seen a skewed towards hi so this (lo+hi)/2 works fine with hi = mid
* Similarly
* lo = mid is skewed towards lo so using (lo+hi)/2 A as mid will result in SEG so instead use
* (hi-lo+1)/2 is skewed towards hi ex. 1+(4-1+1)/2 = 3.5 = 3 so we got ceil(2.5)
* mid = lo + (hi-lo+1)/2
*/

int lower_bound_(vector<int> arr, int target){
    int lo = 0;
    int hi = arr.size()-1;

    while(lo<hi){
        int mid = (lo+hi)/2;

        if(arr[mid] < target)
            lo = mid+1;
        else if(arr[mid] > target) 
            hi = mid-1;
        // Our index needed may be this index mid or may be less than mid. 
        else
            hi = mid;  
    }
    return lo;
}

int upper_bound_(vector<int> arr, int target){
    int lo = 0;
    int hi = arr.size()-1;

    while(lo<hi){
        int mid = lo+(hi-lo+1)/2;   // Note from observation above

        if(arr[mid] < target)
            lo = mid+1;
        else if(arr[mid] > target)
            hi = mid-1;
        // Our index needed may be this index mid or may be greater than mid.
        else
            lo = mid;
    }
    return lo;
}

/*
Rotated sorted array will look something like this
only at pivot arr[pivot] > arr[pivot+1]
   /
  /  
 /          <- case 1 (mid > arr[0])
/ 
      /    
     /      <- case 2 (mid < arr[0])
    /  
ex. {4, 5, 6, 7, 0, 1, 2}
*/
int find_pivot(vector<int> &arr) {

    int lo = 0, hi = arr.size()-1;

    while(lo < hi) {
        int mid = (lo+hi)/2;
        if(arr[mid] > arr[0]){
            if(arr[mid] > arr[mid+1])
                return mid;
            else
                lo = mid+1;
        }
        else{
            if(arr[mid-1] > arr[mid])
                return mid-1;
            else
                hi = mid-1;
        }
    }
    return lo;
}


int pivotedBinarySearch(vector<int> &arr, int target){
    // Task 1: Find the highest elements index 
    // Task 2: Simple binary search in one of the ranges

    int pivot = find_pivot(arr);   

    vector<int> :: iterator it;
    if(target >= arr[0])
        it =  lower_bound(arr.begin(),arr.begin()+pivot,target);
    else
        it =  lower_bound(arr.begin()+pivot+1, arr.end(),target); 
  
    if(*it != target)
        return -1;
    else 
        return it-arr.begin();
}



int main(){
    // Array is sorted then rotated task is to find index of key element.
    vector<int> arr = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    cout << "Index of the element is : "<< pivotedBinarySearch(arr, 2);

    
}
