/*
A minimum distance of src from every other node present in graph with all non-negative weights (optimized algo) OR Negative weighted a-cyclic graph (Non-optimized Algo)
Complexity for dijktra's Algo -> O((V + E) log V)
E-Edges V-Vertices

Slight modification: Think of adding a virtual node which joins an edge to each node. [Similar to multi source BFS]
*/
#include<bits/stdc++.h>
#define LIM 3000
#define INF 1e5+3
typedef pair<int,int> pii;
using namespace std;

//NOTE: Global variables are initailized to 0
vector<pii> adj[LIM];
vector<int> min_dist(LIM,INF);

//Each node in adj list represnts vertex and weight
void addEdge(int u, int v, int wt) 
{ 
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
} 

void dijktra(int src)
{
    //MIN HEAP
    // Keep distace or weight in first plce and indx in second
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    for(int i=0;i<LIM;i++)
        min_dist[i]=INF;                //Init to infinity

    min_dist[src]=0;

    pq.push({0,src});
    while(pq.size())
    {
        
        int curr = pq.top().second;
        pq.pop();

        for(auto u : adj[curr])
        {
            int next = u.first;
            int d = u.second;

            // There are multiple copies of same node in pq with different weights
            // if min_dist[node] is less than d then there is no way that any other node
            // which can be reached via this path with lesser dist.
            // NOTE: Removing this condn will allow negative weights in Dijkstra's algo
            if(min_dist[next] < d)
                continue;
            
            //If previous distance is more than the new distance
            if(min_dist[next] > min_dist[curr]+d)
            {
                pq.push({ d + min_dist[curr], next });
                min_dist[next] = d+ min_dist[curr];
            }                
        }
    }

}

int main()
{
    int V,i,E,src,u,v,wt;

    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;
    cout<<endl;

    for(i=0;i<E;i++)
    {
        cout<<"Enter vertex name u , v and weight: ";
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
    
    cout<<"Enter the source node: ";
    cin>>src;
    dijktra(src);
    cout<<endl;

    cout<<"Min distace all nodes from "<<src<<"is:\n";
    for(int i=0;i<V;i++)
        cout<<i<<"-"<<min_dist[i]<<endl;
}
