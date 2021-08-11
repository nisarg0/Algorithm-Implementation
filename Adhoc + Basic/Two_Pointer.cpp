// Dutch National Flag Problem
// Sot 0,1,2 with a single traversal

/*
* Must satisfy condn
* [start,lo]  = 0
* [hi+1,end]  = 2
* [mid, hi-1] = Don't know
*/
// Array has 0,1,2 as elements sort the array:
void sortColors(vector<int>& arr) {
    int lo=0,mid=0,hi=arr.size()-1;
    //
    while(mid <= hi) {
        if(arr[mid] == 0)
            swap(arr[lo++],arr[mid++]);
        else if(arr[mid] == 1)
            mid++;
        else // arr[mid] = 2
            swap(arr[hi--],arr[mid]);
    }
}