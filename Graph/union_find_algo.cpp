/*
    Que: Given a list of operation makeFriends(a,b) and areFriends(a,b)
    These methods makes a and b friends or checks if they are friends.
    Time  & Space complexcity if done by Graph O(n) & O(n)
    Time  & Space complexcity in case of disjoint set O(m*4) & O(n)
        : m is the number of operations being performed on this dijoint set

    Ref: https://www.youtube.com/watch?v=Kptz-NVA2RE
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> parent; // Keeps track of group representative/parent
vector<int> rnk;    // Keeps track of rank of each element (Rank of leaf is 0 and increase as we go near roor)

// Init the array with each element as it's parent
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
        rnk.push_back(0);
    }
}

// Finds parent of x then parent of parent of x and so on...
// Along with path compression as on return it updates parent[x]
int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

// Joins sets of x to y. Based on the rank of parent for minimum time complexcity.
void weightedUnion(int x, int y)
{
    int xRoot = find(x);
    int yRoot = find(y);

    if (xRoot == yRoot)
        return;

    if (rnk[xRoot] < rnk[yRoot])
        parent[xRoot] = yRoot;
    else if (rnk[yRoot] < rnk[xRoot])
        parent[yRoot] = xRoot;
    else
    {
        parent[yRoot] = xRoot;
        rnk[xRoot] = rnk[xRoot] + 1;
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
