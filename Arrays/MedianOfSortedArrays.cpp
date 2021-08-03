// Problem Link : https://leetcode.com/problems/median-of-two-sorted-arrays/
/*

If we merge two arrays in sorted manner the central values will give us the median

1 4 5
2 6 7 8 9

1 2 4 5 6 7 8 9   -> (5+6)/2 

The left half and right half of this combined array has elements from both arrays

1 4 5   |    INT_MAX     <-  from arr1    (INT_MAX because there was no other element to right, similarly INT_MIN if there's no element to left)
    2   |    6 7 8 9     <-  from arr2

all elements in the left half should be smaller than all elements on right in this configuration 
so basically 5<6 && 2<INT_MAx     (why not compare 2 and 6?  they are from same array so they will be already in sorted order no need to check that)

In general

. . . leftx  |  rightx . . .
. . . lefty  |  righty . . .

leftx<=righty && lefty<=rightx  for valid configuration

Now if we find a point in first array, we can get all others since we divide into halves (refer code)
so find this point using binary search

*/

class Solution {
public:
    double findMedian(vector<int>&a,vector<int>&b){
        int m=a.size();
        int n=b.size();
        int l=0,r=m;
        while(l<=r){
            int partx=l+(r-l)/2;
            int party=(m+n+1)/2-partx;
            int maxlx=(partx==0)?INT_MIN:a[partx-1];
            int minrx=(partx==m)?INT_MAX:a[partx];
            int maxly=(party==0)?INT_MIN:b[party-1];
            int minry=(party==n)?INT_MAX:b[party];
            if(maxlx<=minry&&maxly<=minrx){
                if((m+n)%2==0)
                    return (double)(max(maxlx,maxly)+min(minrx,minry))/2;
                else
                    return (double)(max(maxlx,maxly));
            }else if(maxlx>minry)
                r=partx-1;
            else
                l=partx+1;
        }
        return -1.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size())
        {
            return findMedian(nums1,nums2);
        }  
        else
        {
            return findMedian(nums2,nums1);
        }
    }
};