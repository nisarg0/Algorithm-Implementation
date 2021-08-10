#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(); 
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        
        while(left<=right){
            
            if(height[left]<=height[right]){

                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            }
            else{

                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right]; 
                right--;
            }
        }
        return res;
    }
};


/*

we are concerned with maximum height on left and that on right, 
so we can maintain two prefix and suffix arrays to precompute the max_left and max_right and the answer will be min(max_left,max_right) - curr_height
But since we are only concerned with the minimum of the left and right max we can get rid of the extra space

*/