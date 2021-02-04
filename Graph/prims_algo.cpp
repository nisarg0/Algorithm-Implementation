/*
Minimum Spanning tree is (minimum sum) tree with V-1 edges
Total sum of all the edges must be minimum in O(ElnV)
E-Edges V-Vertices

*/
#include<bits/stdc++.h>
#define LIM 3000
#define INF 1e5+3
using namespace std;

typedef pair<int, int> pii;
vector<pii> adj[LIM];
bool visited[LIM];

//Each node in adj list represnts vertex and weight
void addEdge(int u, int v, int wt) 
{ 
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
} 

int prim()
{
    //MIN HEAP
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    int mst_sum=0;
    int curr_dist=0;

    //Lets assume we start from 0th node
    pq.push({curr_dist,0});

    while(pq.size())
    {
        //we get the smallest possible distance on top of pq
        int curr_node=pq.top().second;
        int curr_dist=pq.top().first;

        pq.pop();

        //if already visited the it must be connected to smallest possible value
        if(visited[curr_node])
        continue;

        visited[curr_node]=true;
        mst_sum += curr_dist;

        for(auto u : adj[curr_node])
        {
            //We push in all the possible adjecent nodes from curr_node
            if(!visited[u.first])
                pq.push({u.second,u.first});
        }
    }
    return mst_sum;
}

int main()
{
    int V,E,i,src,u,v,wt;

    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;
    cout<<endl;

    for(i=0;i<E;i++)
    {
        cout<<"Enter vertex name u , v and weight: ";
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
 
    
    cout<<"Minimum spanning tree sum: ";
    cout<<prim()<<endl;

}