/*
    Que: Given a list of operation makeFriends(a,b) and areFriends(a,b)
    These methods makes a and b friends or checks if they are friends.
    Time  & Space complexcity if done by Graph O(n) & O(n)
    Time  & Space complexcity in case of disjoint set O(m*4) & O(n)
        : m is the number of operations being performed on this dijoint set
    https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends
    Ref: https://www.youtube.com/watch?v=Kptz-NVA2RE
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> parent; // Keeps track of group representative/parent
vector<int> sz;     // Keeps track of num of elements in children below this node

// Init the array with each element as it's parent
void init(int n)
{
    parent.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

// Finds parent of x then parent of parent of x and so on...
// Along with path compression as on return it updates parent[x]
int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]); // remember to call it for parent[x]
}

// Joins sets of x to y. Based on the rank of parent for minimum time complexcity.
void weightedUnion(int x, int y)
{
    int xRoot = find(x);
    int yRoot = find(y);

    if (xRoot == yRoot)
        return;

    if (sz[xRoot] < sz[yRoot])
    {
        parent[xRoot] = yRoot;
        sz[yRoot] += sz[xRoot];
    }
    else
    {
        parent[yRoot] = xRoot;
        sz[xRoot] += sz[yRoot];
    }
    
}

// n - number of fiends
// m - number of operations/relations
int main()
{
    int i, n, m;

    cin >> n >> m;
    init(n);
    for (i = 0; i < m; i++)
    {
        string operation;
        int x, y;
        cin >> operation >> x >> y;
        if (operation == "makeFriend")
        {
            weightedUnion(x, y);
        }
        else if (operation == "isFriend")
        {
            if(find(x) == find(y)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
