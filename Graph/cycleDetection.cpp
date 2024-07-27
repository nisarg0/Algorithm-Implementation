/**
 * @file cycleDetection.cpp
 * @author Nisarg
 * @date 2024-07-27
 * 
 * Detect cycle in directed and adirected graphs
 */

#include<bits/stdc++.h>
#define LIM 1007 

using namespace std;

vector<int> G[LIM];

// Other way of doing this is by bipartiate coloring
bool isCyclicInDirectedGraph(int n, vector<int> inDegree) {

    int i;
    queue<int> q; // NOTE: it stores the topo sorted order

    for(i=0;i<inDegree.size();i++)
        if(inDegree[i] == 0)
            q.push(i);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : G[u]) {
            inDegree[v]--;
            if(inDegree[v] == 0)
                q.push(v);
        }
    }

    // Nodes with more than 1 in degree must be in cycle so they were never inserted in queue.
    for(i=0;i<n;i++)
        if(inDegree[i]!= 0)
            return true;

    return false;
}



int main() {
    int n, edges, u, v;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> edges;

    vector<int> inDegree(n);

    for(int i=0;i<edges;i++) {
        cin >> u >> v;
        G[u].push_back(v);
        inDegree[v]++;
    }

    if(isCyclicInDirectedGraph(n, inDegree))
        cout << "Cycle found in directed Graph" << endl;
}