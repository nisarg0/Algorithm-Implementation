// Not necessarily unique
// Acyclic graph and directed graph
/* 
    Que -> https://cses.fi/problemset/task/1679 
    Time complexcity -> O(V+E)
    Space Complexcity -> O(V)
*/


// Alternate approach can be looking at the in-degree of each node
// Step 1: Find in-degree of each node and maintain it in an array
// step 2: if(indgree[i] == 0) put in queue (bfs) and add it in aur ans array
// do bfs and which ever element we visit reduce its indegree 
// keep on checking while reducing indegree and if its zero add... REPEAT 

#include<bits/stdc++.h>
#define LIM 3000
#define INF 1e5+3
typedef enum {WHITE,GREY,BLACK} col;    //white-no col

using namespace std;

int V,E;
vector<int> G[LIM];
vector<bool> visited(LIM,false);
vector<col> color(LIM,WHITE);

bool notIsCyclic(int u)
{
    color[u] = GREY;

    bool ans=true;

    for(auto v:G[u])
    {
        if(color[v] == GREY)
            return false;
        if(color[v] == BLACK)
            continue;

        ans &= notIsCyclic(v);
        
    }
    color[u] = BLACK;
    return ans;
}

void dfs(int u, stack<int>& stck)
{
    visited[u] = true;
    for(auto v: G[u])
        if(!visited[v])
            dfs(v,stck);
    // NOTE : We insert element in stack after its dfs traversal.
    stck.push(u);
}

int main()
{
	int i,j;
    cin>>V>>E;
    
    for(i=0;i<E;i++)
    {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    // Check for any cycle in graph
    for(i=1;i<=V;i++)
        if(color[i] == WHITE)
            if(!notIsCyclic(i))
            {
                cout << "IMPOSSIBLE\n";
                return;
            }

    // Adding elements to the stack if not visited
    stack<int> stck;
    for(i=1;i<=V;i++)
        if(!visited[i])
            dfs(i,stck);

    // Actually elements are adding in opposite order of topo sort but we 
    // acces the elements in descending order as its a stack.
    for(;!stck.empty();stck.pop())
        cout << stck.top() << " ";
    

}