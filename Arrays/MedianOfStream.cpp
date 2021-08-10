/*

	Time complexity: O(N*(log(N))) 
	Space complexity: O(N)
	
	where N is the total number of elements in the array.

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n){
	
	// To store the medians
	vector<int> medians;
	
	// max heap
	priority_queue<int> lo;  
	
	//min heap                            
    priority_queue<int, vector<int>, greater<int>> hi;   
    
    for(int i = 0; i < n; i++){
    	
    	int num = arr[i];
    	
    	// Add to max heap
    	lo.push(num);                                
		
		// Balancing step, that is inserting the current element at its position that is either less than median or more than median value
        hi.push(lo.top());                        
        lo.pop();

		// Maintain size property, as 'lo' can have utmost one more element than 'hi' or both have equal number of elements
        if (lo.size() < hi.size()) {                    
            lo.push(hi.top());
            hi.pop();
        }
        
        int median;
        
        // For odd number of elements
        if(lo.size() > hi.size()){
        	
        	median = lo.top();
        	
		}
		// For even number of elements
		else{
			
			median = (lo.top() + hi.top())/2;  
			
		}
        
    	medians.push_back(median);
	}
	
	return medians;

}

