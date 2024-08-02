/**
 * @file RandomNum.cpp
 * @author Nisarg Gogate
 *
 * Finding random number between 0 and n-1
 * 1. rand() % n - It gives a random number but it's not evenly distributed.
 * 2. double num = rand() / RAND_MAX;
 *    num * n-1 will be truly random.
 * 
 * Q. Find weighted random number index based on the weight.
 *  https://leetcode.com/problems/random-pick-with-weight/
 * As we can't really add number multiple times to array (space issue),
 * we can add it as a prefix sum. look at this prefix sum from left. we see a array same
 * as the adding number multiple times. Getting numbe in (log n) with lower_bound.
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prefix;

    Solution(vector<int>& w) {
        prefix.push_back(w[0]);
        for(int i=1;i<w.size();i++) {
            prefix.push_back(prefix.back()+w[i]);
        }
    }
    
    int pickIndex() {
        float fraction = (float)rand()/RAND_MAX;
        int num = fraction*prefix.back();

        auto it = lower_bound(prefix.begin(), prefix.end(), num*prefix.back());

        return it-prefix.begin();
    }
};
