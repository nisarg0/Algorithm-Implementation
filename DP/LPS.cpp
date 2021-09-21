#include<bits/stdc++.h>
using namespace std;

/* solution is based on gap strategy
Reference  --> https://www.youtube.com/watch?v=WpYHNHofwjc

Every diagonal of the matrix can be uniquely identified by a gap value which represents the gap between i and j 
The gap 0 basically represents the individual elements which are themselves palindromes
ex. str = abcda  gaps = a | b | c | d | a ==> 4 gaps (cnt of |)
Now for any particular i,j it is a palindrome if str from i+1 to j-1 is a palindrome and characters at i and j are equal
So, dp[i][j] = dp[i+1][j-1] && str[i]==str[j]
Here dp[i+1][j-1] represents the diagonally lower element which we have already computed in previous gap iterations

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int start = -1;
        int end = -1;
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g ; j<n ; i++,j++)
            {
                if(g==0)
                {
                    dp[i][j] = true;
                }
                
                else if(g==1)
                {
                    dp[i][j] = (s[i]==s[j]);
                }
                
                else
                {
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                }
                
                if(dp[i][j])
                {
                    start = i;
                    end = j;
                }
            }
        }        
        return s.substr(start,end-start+1);   
    }
};


/*
* Alternte Soln can be made from observation that palindrome has same elements from center.
* So choose center and find left of center and right of center as 2 pointers compare and get length.
* Optimization - if(isPalindrome(i,j)) is true and S[i-1] == S[j+1] then isPalindrome(i-1,j+!1) is also true.
* This operation is to be done for odd as well as even. O(n) Time and O(1) Space.
*/
