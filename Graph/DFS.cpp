
/*
We can  peform multisorurce bfs also for the problems of type 
1. there are k hospitals and n cities and they are connected so find closest hostila form each city
Add all hospitals as src and do bfs on unvisited nodes so ...

Time Complexity: O(V + E)

*/
#include<bits/stdc++.h>
#define LIM 3000
#define INF 1e5+3
using namespace std;

vector<int> adj[LIM];
bool visited[LIM];

void addEdge(int u, int v) 
{ 
    adj[u].push_back(v);
    adj[v].push_back(u);
} 

void dfs_iterative(int src)
{
    memset(visited,0,sizeof(visited));
    stack<int> stck;
    stck.push(src);

    while(stck.size())
    {
        int u=stck.top();
        stck.pop();

        visited[u]=true;
        cout<<u<<" ";        

        for(auto v:adj[u])
        {
            if(!visited[v])
                stck.push(v);
        }
    }
    memset(visited,0,sizeof(visited));
}



void dfs_recursive(int u)
{
    if(visited[u])
    return ;

    visited[u]=true;
    cout<<u<<" ";

    for(int v : adj[u])
    {
        if(!visited[v])
            dfs_recursive(v);
    }
}




int main()
{
    int V,i,src,u,v,wt;

    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;
    

    for(i=0;i<E;i++)
    {
        cout<<i+1<<". Enter vertex name u and v:  ";
        cin>>u>>v;
        addEdge(u,v);
    }
   

    cout<<"Enter source node for iterative dfs: ";
    cin>>src;
    cout<<"Iterative_DFS=> ";
     dfs_iterative(0);
     cout<<endl;

    cout<<"Enter source node for recursive dfs: ";
    cin>>src;
    cout<<"Recursive_DFS=> ";
}
