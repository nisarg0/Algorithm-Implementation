# Graphs

Minimum Spanning Tree
- **Prim's Algorithm**: Add `{wt, node}` to min heap to visit all nodes only once.


Shortest Distance from `src` node to all nodes in Graph
- **Dijkstra Algorithm**: Greedy approach choose the closest node from each node and store in min heap. *[+ve weights]*.
- **Bellman Ford**: Loop V times over all edges in graph and set `dist[v] = min(dist[v], dist[u]+wt(u,v))`. *[-ve weights]*

Shortest Distance between all pairs of nodes in Graph
- **Floyd Warshall Algorithm**:  For every path which passes through k, `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])` 