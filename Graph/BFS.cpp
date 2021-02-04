#include<bits/stdc++.h>

using namespace std;
#define LIM 1007

vector<int> adj[LIM];
// vector<int> dist(LIM,-1);
// vector<int> parent(LIM,-1);
int visited[LIM];

void addEdge(int u, int v) 
{ 
    adj[u].push_back(v);
    adj[v].push_back(u);
} 

void bfs(int src)
{
    queue<int> q;
    int d=0;
    // dist[src] = d;
    // parent[src] = -1;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout<<u<<" ";
        for(int v : adj[u])
        {
            if(!visited[v])
            {
                // dist[v] = dist[u] + 1;
                // parent[v] = u;
                
                visited[v]=true;    //NOTE : We put visited here inside the inner loop
                q.push(v);
            }
                
        }
    }
}


int main()
{
    int V,i,src,u,v,wt,E;

    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;
    

    for(i=0;i<E;i++)
    {
        cout<<i+1<<". Enter vertex name u and v:  ";
        cin>>u>>v;
        addEdge(u,v);
    }
   

    cout<<"Enter source node for iterative bfs: ";
    cin>>src;
    cout<<"BFS=> ";
    bfs(src);
    cout<<endl;


}