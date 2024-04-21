/**
 * @file LongestPanlidromicSubsequence.cpp
 * @author Nisarg Gogate
 * @brief Find Longest palindrome subsequence
 * Or Find k -palindrome. Remove at max k characters such that the string formed is a palindrome.
 */

#include <bits/stdc++.h>

using namespace std;

// Longest common sequence between two strings
// If a[i] == b[j] dp[i][j] = dp[i-1][j-1] + 1; else max(dp[i-1][j], dp[i][j-1])
int LCS(string a, string b, int n, int m)
{
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// Trying to mimic the above code using same thing using two pointers
int longestPalindromeSubseq(string str)
{
    int i, j, n = str.size();
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0)); // dp[i][j] denotes the string i to j (inclusive)
    for (i = n - 1; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (j = i+1; j < n; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            if (str[i] == str[j])
            {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
            }
        }
    }
    return dp[0][n-1];
}

// Optimized above solution to use O(N) space
int longestPalndromeSubsequenceOptimzed(string str) {
     int n = str.size();
        vector<int> dp(n, 0), dpPrev(n, 0); // prev denotes the prev row of above solution.
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (str[i] == str[j]) {
                    dp[j] = dpPrev[j-1] + 2;
                } else {
                    dp[j] = max(dpPrev[j], dp[j-1]);
                }
            }
            dp.swap(dpPrev);
        }
        return dpPrev[n-1];
}

int longestPalindromeSubseqUsingLCS(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return LCS(s, s2, s.size(), s.size());
}

int main()
{
    string str = "abccefba";
    cout << "Longest Palindromic subseq using LCS: " << longestPalindromeSubseqUsingLCS(str) << endl;
    cout << "Longest Palindromic subseq: " << longestPalindromeSubseq(str) << endl;
    cout << "Longest Palindromic subseq with O(N) Space Optmization: " << longestPalndromeSubsequenceOptimzed(str) << endl;
}