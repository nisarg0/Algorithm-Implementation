// Note : Is apllicable on;y on trees
// Precomutation : NLog(N)
// Query output : Log(N) 
// N is basically the max height possible
// Q. Find element kth place above x.

#include<bits/stdc++.h>
const int LIM = (int)2e5+3;

using namespace std;

// number of vertices
int V;

// elements of trees are stored from 0
vector<int> tree[LIM];
vector<int> parent(LIM);
vector<int> depth(LIM);
// up(i,j) stores element 2^j steps above (element)i. 
int up[LIM][20];

void addEdge(int u, int v) 
{ 
    tree[u].push_back(v);
    tree[v].push_back(u);
}

// Precomputes the up using dp.
void  binary_lifting(int u, int pa)
{
    // up by 2^0 steps
    up[u][0] = pa;

    for(int i=1;i<20;i++)
    {
        if(up[u][i-1] != -1)
            up[u][i] = up[ up[u][i-1] ][i-1];
        else
            up[u][i] = -1;
    }

    // Vanilla dfs
    for(auto v: tree[u])
        if(v != pa)
            binary_lifting(v,u);    
}

// returns the node_val at dist h above node
// if no node is present returns -1
int ans_query(int node, int h)
{
    // node should not be -1
    for(int i=0;i<20 and node != -1;i++)
    {
        // if ith bit of h is set
        if(h & 1<<i)
            node = up[node][i];
    }
    return node;
}

int main()
{
    int i,src,u,v,q,x,k;

    cout<<"Enter number of vertices: ";
    cin>>V;
    
    for(i=0;i<V-1;i++)
    {
        cout<<i+1<<". Enter vertex name u and v:  ";
        cin>>u>>v;
        addEdge(u,v);
    }
   
    src = 0;
    binary_lifting(src,-1);

    cout<<"Enter number of queries: ";
    cin>>q;
    
    for(i=0;i<q;i++)
    {
        cin >> x >> k;
        cout << "Node :" << ans_query(x,k) << " is at a dist " 
        << k << "from " << x << endl;
    }
}
