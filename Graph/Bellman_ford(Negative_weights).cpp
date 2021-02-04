/*
Reference -> https://www.youtube.com/watch?v=FtN3BYH2Zes
Minimum distance of src from every other node present in graph
Complexity for Bellman Ford's Algo -> O(E*V)  
E-Edges V-Vertices
*/
#include<bits/stdc++.h>
#define LIM 3000
#define INF 1e5+3

using namespace std;


//NOTE: Here reprentation of graph is done a bit differnetly 
typedef pair<int,int> pii;

vector<vector<int>> G(LIM,vector<int>(3));
vector<int> min_dist(LIM,INF);
int V,E;

/*
IMP NOTE: If there is a cycle with total sum negative then this algo WON'T WORK
We baically relax the edges V-1 times
*/
void bellman_ford(int src)
{
    min_dist[src] = 0;
    int u,v,k;
    for(k=0;k<V-1;k++)
    {
        for(auto itr : G)
        {
            int u = itr[0];
            int v = itr[1];
            int wt = itr[2];

            min_dist[v] = min(min_dist[v],min_dist[u]+wt);
        }
    }

    // If the min min_dist is still changing even after V-1 iterstions means there is no soln.
    for(auto itr : G)
    {
        int u = itr[0];
        int v = itr[1];
        int wt = itr[2];

        if(min_dist[v] > min_dist[u]+wt)
        {
            cout << "There is a negtive cycle\n";
            break;
        }
    }
    
}

int main()
{
    int i,src=0,u,v,wt;

    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;
    cout<<endl;

    for(i=0;i<8;i++)
    {
        cout<<"Enter vertex name u , v and weight: ";
        cin>>u>>v>>wt;

        G[i][0] = u;
        G[i][1] = v;
        G[i][2] = wt;
    }
    
    cout<<"Enter the source node: ";
    cin>>src;
    bellman_ford(src);
    cout<<endl;

    cout<<"Min distace all nodes from "<<src<<"is:\n";
    for(int i=0;i<V;i++)
        cout<<i<<" : "<<min_dist[i]<<endl;
}