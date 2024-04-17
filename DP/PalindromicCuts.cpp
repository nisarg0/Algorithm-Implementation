/**
 * @file PalindromicCut.cpp
 * @author Nisarg Gogate
 * @brief Cases when we want to divide array/string into parts and maximize/minimize
 *  something about those parts. We can try MCM
 *
 * Ex. Find min numbers of cuts needed such that each substring is a palindrome.
 * @ref https://leetcode.com/problems/palindrome-partitioning-ii/description/
 */

#include <bits/stdc++.h>

using namespace std;

int SIZE = 2002;
vector<vector<int>> dp(SIZE, vector<int>(SIZE, -1));

bool isPalindrome(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++, j--;
    }
    return true;
}

/**
 * @brief Usually MCM time complexcity is O(n^3) but here as we are checking if it's
 * a palindrome time complexcity is O(n^4)
 */
int findCuts(string str, int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];

    // String can't be cut if it's length is already less than 1
    if (l >= r)
        return dp[l][r] = 0;

    if (isPalindrome(str.substr(l, r - l + 1)))
        return 0;

    int ans = r - l;

    // NOTE: k should not be equal to r to avoid inf loop
    for (int k = l; k < r; k++)
    {
        int left = dp[l][k] == -1 ? findCuts(str, l, k) : dp[l][k];
        int right = dp[k + 1][r] == -1 ? findCuts(str, k + 1, r) : dp[k + 1][r];

        ans = min(ans, left + right + 1);
    }
    return dp[l][r] = ans;
}



/**
 * @brief Idea is to find if a string is palindrom or not in O(1) using dp
 * Also, we don't really need to know number of plindromes between i and j.
 * 
 * Here dp[i] represents number of palindromes from 0->i.
 * So, dp[i] = dp[k] + 1 where k->i is a plindrome.
 * 
 * Time Complexcity: O(n^2), Space Complexcity: O(n^2)
 */
int findCutsOptimized(string str) {
    int n = str.size();
    vector<int> dp(n, 0); 
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false)); 

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (str[i] == str[j] && (len <= 2 || isPalindrome[i + 1][j - 1])) {
                isPalindrome[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (isPalindrome[0][i]) {
            dp[i] = 0; 
        } else {
            dp[i] = i; // suppose we need to cut at each index
            for (int j = 0; j < i; ++j) {
                if (isPalindrome[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1); 
                }
            }
        }
    }

    return dp[n - 1];
}

/**
 * @brief We take advantage of property that palindrome is same from front and back
 * We 
 *
 * Time Complexcity: O(n^2), Space Complexcity: O(n)
 * 
 * @param str 
 * @return int 
 */
int findCutsMostOptimized(string str) {
    int n = str.size();
    vector<int> dp(n+1);
    for (int i = 0; i <= n; i++) dp[i] = i-1; // note dp[0] will be set -1. This helps us with a cleaner code
    for(int mid = 0; mid < n; mid++){
    //palindrome of odd lengths 1,3,5...
    for(int len = 0; mid-len >= 0 && mid+len < n; len++)
        if(str[mid-len] == str[mid+len])
            dp[mid+len+1] = min(dp[mid+len+1], dp[mid-len]+1);
    //palindrome of even lengths 2,4,6...
    for(int len = 0; mid-len >= 0 && mid+len+1 < n; len++)
        if(str[mid-len] == str[mid+len+1])
            dp[mid+len+2] = min(dp[mid+len+2], dp[mid-len]+1);
    }
    return dp[n];
    
}

int main()
{
    string str = "aabacd";
    cout << "Minimum cuts needed " << findCuts(str, 0, str.size() - 1) << "\n";
}
