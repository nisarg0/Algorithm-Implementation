#include<bits/stdc++.h>

using namespace std;
#define LIM 1007
typedef enum {NOCOLOR,BLUE,RED} col;


vector<int> adj[LIM];
vector<col> color(LIM,NOCOLOR);


void addEdge(int u, int v) 
{ 
    adj[u].push_back(v);
    adj[v].push_back(u);
} 

void bfs()
{
    queue<int> q;
    int d=0;

    for(int i=1;i<LIM;i++)
    {
        // if we find a new part of G
        if(color[i] == NOCOLOR)
            q.push(i);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            // If no color is given give a random color
            if(color[u] == NOCOLOR)
                color[u] = RED; 

            for(int v : adj[u])
            {
                if(color[v] == NOCOLOR)
                {
                    if(color[u] == RED)
                        color[v] = BLUE;
                    else
                        color[v] = RED;

                    q.push(v);
                }
                else
                {
                    // If adjecent nodes have same color
                    if(color[u] == color[v])
                    {
                        cout << "IMPOSSIBLE";
                        return;
                    }
                }
                    
            }
        }
    }
    cout << "Color for ith node is: " << endl;
    for(int i=1;i<LIM;i++)
    {
        cout << i<< " " <<color[i];
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
   

    // Printing color of each node in graph
    bfs();



}