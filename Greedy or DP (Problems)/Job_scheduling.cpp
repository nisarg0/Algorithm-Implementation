// Link --> https://leetcode.com/problems/maximum-profit-in-job-scheduling/

// You're given the startTime, endTime and profit arrays, return the maximum profit 
// you can take such that there are no two jobs in the subset with overlapping time range.
// 1 <= startTime[i] < endTime[i] <= 10^9

// NOT A GREEDY SOLN
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<vector<int>> jobs;
    for (int i = 0; i < n; ++i) {
        jobs.push_back({endTime[i], startTime[i], profit[i]});
    }

    // Sort according to end time of jobs
    sort(jobs.begin(), jobs.end());

    // dp[i] stores maximum profit at time = i
    map<int, int> dp = {{0, 0}};
    for (auto& job : jobs) {
            // Finding the profit at largets end time before current job's start iem 
        int cur = prev(dp.upper_bound(job[1]))->second + job[2];
        if (cur > dp.rbegin()->second)
            dp[job[0]] = cur;
    }
    return dp.rbegin()->second;
}


// Link -->https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// N jobs takes 1 unit of time to complete and jth job has job[j] as deadline.
// Find max profit? 

/*
* Sort according to the profits (decreasing)
* Do the process as late as possible (Close to deadline)
* U have the ans...
*/