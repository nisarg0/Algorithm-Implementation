// Reference -> https://www.youtube.com/watch?v=2EpX9LkO2T0
// NOTE : We can't update efficiently
// Precomutation- O(NLogN) Query - O(LogN)
// If query Function asked is Idempotent(F(a,a)=a) we can solve 1 query in O(1*op). op is time taken by the operator(gcd takes more time) 
// ex. max(a,a)=a , min, gcd, bitwie-or, bitwise-and, etc.

#include<bits/stdc++.h>
using namespace std;

// #define int long long 

const int LIM = (int)1e7;
const int K = (int)(25);


// jth column in ith row represents the value of function from i to i+2^j.
// st[i][j] = f(i to i+2^j)
int st[LIM][K+1];    //30 = log2 LIM

int f(int a, int b)
{
    return min(a,b);
}

// range [i,i+2^j−1] of length 2^j splits nicely into 
// the ranges [i,i+2^(j−1)−1] and [i+2^(j−1),i+2^(j−1)], both of length  2^(j−1).
void init(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        st[i][0] = (arr[i]);

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = f(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query_normal(int l,int r)
{
    int ans = INT_MAX;
    // from 2^30m till 2^0 whch are the numbers we can subtract from r-l+1 till its not 0
    // we basically add values of set bits from st.
    for(int i=K;i>=0;i--)
    {
        if((1<<i) <= r-l+1)
        {
            ans = min(ans,st[l][i]);
            l += 1<<i;
        }
    }
    return ans;
}

// we can split the range [1,6] into the ranges [1,4] and [3,6]
// Both in power of 2 (we used data from [3,4] again) So must be idempotent
int query_idempotent(int l, int r)
{
    int j = log2(r-l+1);
    return f(st[l][j], st[r+1-(1<<j)][j]);;
}

int main(void)
{
    int arr[15] = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
    int n = sizeof(arr)/sizeof(int);
    init(arr,n);

    cout<<"Minimum number in O(NLogN) in range: "<<query_normal(2,3)<<endl;
    cout<<"Minimum number in O(1) in range: "<<query_idempotent(2,3)<<endl;
    return 0;
}