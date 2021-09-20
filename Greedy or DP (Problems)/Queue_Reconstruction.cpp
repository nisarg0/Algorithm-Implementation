/*Given n peps with [hi,ki] where ki denotes number of peps with height
* greater than or eqaul to hi to its left in final queue
* https://leetcode.com/problems/queue-reconstruction-by-height/

* Soln -> Time Complexcity O(n logn)
*/
#include<bits/stdc++.h>
using namespace std;

// Return The sequence which satisfies the given condition
vector<pair<int,int>> queue_reconstruction(vector<pair<int,int>> people) {
    // Observations - 
    // We need to count people with height taller or equal to in front of them
    // Smaller person is completely irrelevant
    // For smallest person all persons are greater than him
    sort(people.begin(),people.end(),[](pair<int,int> p1,pair<int,int> p2){
        return p1.first>p2.first or
               (p1.first == p2.first and p1.second<p2.second);
    });
    // can be written as compare function as well
    vector<pair<int,int>> ans;
    
    for(int i=0;i<people.size();i++) 
        // We have to insert the person into people[i].second position
        // as all the k persons before that index are greater than or equal in height as person[i] 
        ans.insert(ans.begin()+people[i].first,people[i]);
    // Insert function takes in 2 param - position (iterator)  - value
    
}