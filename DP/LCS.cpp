/**
 * @file LCS.cpp
 * @author Nisarg
 * @brief Longest comman Subsequence in given two strings
 * 
 */

#include<bits/stdc++.h>

using namespace std;

void LCS(string a, string b) {
    int n = a.size(), m = b.size();

    vector<vector<int> > dp(n+1, vector<int> (m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Longest comman string's length is " << dp[n][m] << endl;

    int i = n+1, j = m+1;
    string ans = "";
    while (i > 0 || j > 0) {
        if (a[i-1] == b[j-1]) {
            ans += a[i-1];
            i--; j--;
        }
        else {
            if (dp[i-1][j] < dp[i][j-1]) 
                j--;
            else 
                i--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << "Longest common subsequence is " << ans << endl;
}


void LCS_SpaceOptmized(string a, string b) {
    int n = a.size(), m = b.size();

    vector<int> dp(m+1, 0);
    vector<int> prev(m+1, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) {
                dp[j] = prev[j-1] + 1;
            }
            else {
                dp[j] = max(dp[j-1], prev[j]);
            }
        }
        prev = dp;
    }

    cout << "Longest comman string's length is " << prev[m] << endl;
}

int main() {

    string str1 = "abcda";
    string str2 = "abcbcba";

    int m = str1.length();
    int n = str2.length();

    LCS(str1, str2); 
    LCS_SpaceOptmized(str1, str2);

    return 0;
}