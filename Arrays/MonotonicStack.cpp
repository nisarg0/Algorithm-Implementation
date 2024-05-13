/**
 * @file MonotonicStack.cpp
 * @author Nisarg 
 * @brief A monotonic stack is a stack whose elements are monotonically increasing or descreasing.
 * Sometimes we store the index of the elements in the stack and make sure the elements corresponding to those indexes in the stack forms a mono-sequence
 * 
 * @question Find next smaller/greater element for each element in O(n) Time complexity.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr) {
    stack<pair<int,int> > stck;
    int i,n = arr.size();
    vector<int> ans(n);
    for(i=0;i<n;i++) { // Can be written as n->1 
        if(stck.empty()) {            
            stck.push({arr[i], i});
            continue;
        }
        while(!stck.empty() && stck.top().first < arr[i])  {
            ans[stck.top().second] = arr[i];
            stck.pop();
        }
        stck.push({arr[i],i});   
    }

    while(!stck.empty()) {
        ans[stck.top().second] = -1;
        stck.pop();
    }
    return ans;
}

// Stack always array indices where values are in increasing order.
vector<int> nextSmallerElement(vector<int> arr) {
    stack<int> stck;
    int i,n = arr.size();
    vector<int> ans(n, -1);

    for(i=0;i<n;i++) {
        while(!stck.empty() and arr[i] < arr[stck.top()]) {
            ans[stck.top()] = arr[i];
            stck.pop();
        }
        stck.push(i);
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 7, 2, 3, 1, 8};

    vector<int> nextGreater = nextGreaterElement(arr);
    cout << "\nNext Greater Element: ";
    for (auto ele: nextGreater) 
            cout << ele << " ";
    vector<int> nextSmaller = nextSmallerElement(arr);
    cout << "\nNext Smaller Element: ";
    for (auto ele: nextSmaller) 
            cout << ele << " ";

}