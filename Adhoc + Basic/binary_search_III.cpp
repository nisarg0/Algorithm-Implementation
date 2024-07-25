#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right-left)/2; // To help with out of bounds
        if (arr[mid] >= target) { // we want the value in ans if the target exists
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}

int upperBound(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right-left)/2; // To help with out of bounds
        if (arr[mid] > target) { // we want a greater than target value.
            result = mid - 1;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}