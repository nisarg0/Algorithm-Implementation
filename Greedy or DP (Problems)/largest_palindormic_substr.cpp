// HOW TO APPLY DP FOR SOME PALINDROME STRING QUESTION
// Reference  --> https://www.youtube.com/watch?v=WpYHNHofwjc
void longest_palindrome(string str){
    int i,j,n=str.size();
    // dp[i][j] - true represntes the the string from i to j is a palindrome. 
    vector<vector<bool>> dp(n,vector<bool> (n,false));
    
    // we define a term gaps. 
    // ex. str = abcda  gaps = a | b | c | d | a ==> 4 gaps (cnt of |)
    // Diagonal traversal Question 
    // Always used gaps fandda
    int len = 0; //length of longest palindrome
    for(int g=0; g<n; g++) {
        for(i=0,j=g;j<str.size();i++,j++) {
            // Single char is a palindrome
            if(g == 0) {
                dp[i][j] = true;
            }
            else if(g == 1){
                if(str[i] == str[j])
                    dp[i][j] = true;
            }
            else {
                if(str[i] == str[j] and dp[i+1][j-1])
                    dp[i][j] = true
            }
            len = max(len,gap+1);
        }
    }

    return len;
}


