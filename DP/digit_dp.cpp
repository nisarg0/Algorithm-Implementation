// Reference -> https://www.youtube.com/watch?v=heUFId6Qd1A
// F(x) returns boolean value
// General -> How many integers x in range [0,R] obey F(x)
// Example -> Find cnt of numbers betn L and R which have a sum of digits = x
// 1 <= L <= R <= 10^18
// 1 <= X <= 180
#include<bits/stdc++.h>
using namespace std;

// Max no of dights in a number be 100(Not needed)
int dp[101][181][2];
// boolena value tight stores checks if we can place any number at indx(R.size()-n) or we need we can place till ub
int digit_dp(string R,int n,int sum,bool tight)
{
    if(sum < 0)
        return 0;
    if(n==0)
    {
        if(sum == 0)
            return 1;
        return 0;
    }

    if(dp[n][sum][tight] != -1)
        return dp[n][sum][tight];

    // ub is upper bound till which digit we can use at that particular index
    int ub = 9,ans=0;
    if(tight)
        ub = (R[R.size()-n]-'0');
    for(int i=0;i<=ub;i++)
    {
        // Once a number is non tight it won't ever be tight in future
        // A tight will be tight only if we keep on passing the higest number possible at that indx
        ans += digit_dp(R,n-1,sum-i,tight&(i==ub));
    }
    return dp[n][sum][tight] = ans;
}

int main()
{
    string L = "";
    string R = "490447834749";
    int x = 20;
    memset(dp,-1,sizeof dp);
    cout<<digit_dp(R,R.size(),x,1);
}