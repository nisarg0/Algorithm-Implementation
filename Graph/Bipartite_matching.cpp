/**
 * @file Bipartite_matching.cpp
 * @author Nisarg
 * @brief Question: Given n job appplicants and m jobs. Given ith applicant with letter from jth job
 * Find maximum number of job applicants which can get a job. jobs[i][j] = 1 / 0
 *
 * @ref: https://www.geeksforgeeks.org/maximum-bipartite-matching/
 * @ref: https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
 * @ref: https://leetcode.com/problems/maximum-number-of-accepted-invitations/solutions/1978859/python-hungarian-algorithm-easy-to-understand/
 */

#include <bits/stdc++.h>

using namespace std;

int jobs = 6, applicants = 6;

vector<vector<int> > G;
vector<int> currentMatching(jobs, -1);       // Job i mapped with currentMatching[i] applicant.
vector<bool> visited(applicants);            // Usual use so that dfs doesn't visit same vertex again

/**
 * Main idea behind the logic is a job applicant will only leave job if he/she gets some other job.
 *
 * @return bool : true a new match is added
 */

bool findMaxBiPartiteMatching(int u) // applicant
{
    if (visited[u]) // if applicant is already assigned or checked no need to recheck
        return false;

    visited[u] = true;

    // Checking if vth job if already selected by some applicant
    for (auto v : G[u]) {
        // if current matching is available for v or if v can find some other job
        // checking if selected applicant for job v can find some other job
        if ( currentMatching[v] == -1 || findMaxBiPartiteMatching(currentMatching[v]) ) {
            currentMatching[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    G = {
            {1, 2}, // Applicant 0 has {1, 2} job offers
            {0, 3}, // Applicant 1 has {0, 3} job offers 
            {2}, 
            {2, 3}, 
            {}, 
            {5}
        };

    int ans = 0;
    for (int applicant = 0; applicant < applicants; applicant++)
    {
        visited.assign(applicants, false);
        if(findMaxBiPartiteMatching(applicant))
            ans++;
    }

    cout << "Max num of G matching with applicants is " << ans;
}
