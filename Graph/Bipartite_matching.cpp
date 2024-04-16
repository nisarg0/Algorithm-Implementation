/**
 * @file Bipartite_matching.cpp
 * @author Nisarg
 * @brief Question: Given n job appplicants and m jobs. Given ith applicant with offerletter from jth job
 * Find maximum number of job applicants which can get a job. jobs[i][j] = 1 / 0
 *
 * @ref: https://www.geeksforgeeks.org/maximum-bipartite-matching/
 * @ref: https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
 */

#include <bits/stdc++.h>

using namespace std;

int n = 6, m = 6;

vector<vector<int> > G;
vector<int> currentMatching(n, -1); // denotes ith job applicant mapped with currentMatch[i] job or -1 if no job
vector<bool> visited(n);            // Usual use so that dfs doesn't visit same vertex again

/**
 * Main idea behind the logic is a job applicant will only leave job if he/she gets some other job.
 *
 * @return bool : true a new match is added
 */

bool findMaxBiPartiteMatching(int u)
{
    if (visited[u])
        return false;

    visited[u] = true;

    for (auto v : G[u]) {
        // if currentMatching is available for v or if v can find some other job
        if ( currentMatching[v] == -1 || findMaxBiPartiteMatching(v) ) {
            currentMatching[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    G = {{1, 2}, {0, 3}, {2}, {2, 3}, {}, {5}};

    int ans = 0;
    for (int person = 0; person < n; person++)
    {
        visited.assign(n, false);
        if(findMaxBiPartiteMatching(person))
            ans++;
    }

    cout << "Max num of G matching with applicants is " << ans;
}