/**
 * @file FloydWarshall.cpp
 * @author Nisarg
 * @brief Multi Source shortest path algorithm. Find shortest paths from all nodes to all other nodes.
 * Logic: dist[i][j] =  min (dist[i][j]],dist[i][k] + dist[k][j])
 * Time complexity: O(V^3)
 * @date 2024-07-28
 */

#define INF 1e5+3

#include<bits/stdc++.h>

using namespace std;

void findShortestDist(vector<vector<int>>& matrix) {
    int n = matrix.size(), i, j, k;

    // initialize matrix with INF dist where no roads are available
    // initialize matrix with 0 dist where i == j
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == -1) matrix[i][j] = INF;
            if (i == j) matrix[i][j] = 0;
        }
    }

    // Floyd Warshall's algorithm
    for(k = 0; k < n; k++) 
        for(i = 0; i < n; i++) 
            for(j = 0; j < n; j++) 
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
}


int main() {
    int V = 4;
    vector<vector<int> > matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

    findShortestDist(matrix);
    

    cout << "Following matrix shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF)
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}